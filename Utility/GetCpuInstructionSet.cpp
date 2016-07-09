#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#if _MSC_VER >=1400	// VC2005��֧��intrin.h
#include <intrin.h>	// ����Intrinsics����
#else
#include <emmintrin.h>	// MMX, SSE, SSE2
#endif


// CPUIDFIELD
typedef INT32 CPUIDFIELD;

#define  CPUIDFIELD_MASK_POS	0x0000001F	// λƫ��. 0~31.
#define  CPUIDFIELD_MASK_LEN	0x000003E0	// λ��. 1~32
#define  CPUIDFIELD_MASK_REG	0x00000C00	// �Ĵ���. 0=EAX, 1=EBX, 2=ECX, 3=EDX.
#define  CPUIDFIELD_MASK_FIDSUB	0x000FF000	// �ӹ��ܺ�(��8λ).
#define  CPUIDFIELD_MASK_FID	0xFFF00000	// ���ܺ�(���4λ �� ��8λ).

#define CPUIDFIELD_SHIFT_POS	0
#define CPUIDFIELD_SHIFT_LEN	5
#define CPUIDFIELD_SHIFT_REG	10
#define CPUIDFIELD_SHIFT_FIDSUB	12
#define CPUIDFIELD_SHIFT_FID	20

#define CPUIDFIELD_MAKE(fid,fidsub,reg,pos,len)	(((fid)&0xF0000000) \
	| ((fid)<<CPUIDFIELD_SHIFT_FID & 0x0FF00000) \
	| ((fidsub)<<CPUIDFIELD_SHIFT_FIDSUB & CPUIDFIELD_MASK_FIDSUB) \
	| ((reg)<<CPUIDFIELD_SHIFT_REG & CPUIDFIELD_MASK_REG) \
	| ((pos)<<CPUIDFIELD_SHIFT_POS & CPUIDFIELD_MASK_POS) \
	| (((len)-1)<<CPUIDFIELD_SHIFT_LEN & CPUIDFIELD_MASK_LEN) \
	)
#define CPUIDFIELD_FID(cpuidfield)	( ((cpuidfield)&0xF0000000) | (((cpuidfield) & 0x0FF00000)>>CPUIDFIELD_SHIFT_FID) )
#define CPUIDFIELD_FIDSUB(cpuidfield)	( ((cpuidfield) & CPUIDFIELD_MASK_FIDSUB)>>CPUIDFIELD_SHIFT_FIDSUB )
#define CPUIDFIELD_REG(cpuidfield)	( ((cpuidfield) & CPUIDFIELD_MASK_REG)>>CPUIDFIELD_SHIFT_REG )
#define CPUIDFIELD_POS(cpuidfield)	( ((cpuidfield) & CPUIDFIELD_MASK_POS)>>CPUIDFIELD_SHIFT_POS )
#define CPUIDFIELD_LEN(cpuidfield)	( (((cpuidfield) & CPUIDFIELD_MASK_LEN)>>CPUIDFIELD_SHIFT_LEN) + 1 )

// ȡ��λ��
#ifndef __GETBITS32
#define __GETBITS32(src,pos,len)	( ((src)>>(pos)) & (((UINT32)-1)>>(32-len)) )
#endif


#define CPUF_SSE4A	CPUIDFIELD_MAKE(0x80000001,0,2,6,1)
#define CPUF_AES	CPUIDFIELD_MAKE(1,0,2,25,1)
#define CPUF_PCLMULQDQ	CPUIDFIELD_MAKE(1,0,2,1,1)

#define CPUF_AVX	CPUIDFIELD_MAKE(1,0,2,28,1)
#define CPUF_AVX2	CPUIDFIELD_MAKE(7,0,1,5,1)
#define CPUF_OSXSAVE	CPUIDFIELD_MAKE(1,0,2,27,1)
#define CPUF_XFeatureSupportedMaskLo	CPUIDFIELD_MAKE(0xD,0,0,0,32)
#define CPUF_F16C	CPUIDFIELD_MAKE(1,0,2,29,1)
#define CPUF_FMA	CPUIDFIELD_MAKE(1,0,2,12,1)
#define CPUF_FMA4	CPUIDFIELD_MAKE(0x80000001,0,2,16,1)
#define CPUF_XOP	CPUIDFIELD_MAKE(0x80000001,0,2,11,1)


// SSEϵ��ָ���֧�ּ���. simd_sse_level �����ķ���ֵ��
#define SIMD_SSE_NONE	0	// ��֧��
#define SIMD_SSE_1	1	// SSE
#define SIMD_SSE_2	2	// SSE2
#define SIMD_SSE_3	3	// SSE3
#define SIMD_SSE_3S	4	// SSSE3
#define SIMD_SSE_41	5	// SSE4.1
#define SIMD_SSE_42	6	// SSE4.2

const char*	simd_sse_names[] = {
	"None",
	"SSE",
	"SSE2",
	"SSE3",
	"SSSE3",
	"SSE4.1",
	"SSE4.2",
};


// AVXϵ��ָ���֧�ּ���. simd_avx_level �����ķ���ֵ��
#define SIMD_AVX_NONE	0	// ��֧��
#define SIMD_AVX_1	1	// AVX
#define SIMD_AVX_2	2	// AVX2

const char*	simd_avx_names[] = {
	"None",
	"AVX",
	"AVX2"
};



char szBuf[64];
INT32 dwBuf[4];

#if defined(_WIN64)
// 64λ�²�֧���������. Ӧʹ��__cpuid��__cpuidex��Intrinsics������
#else
#if _MSC_VER < 1600	// VS2010. ��˵VC2008 SP1֮���֧��__cpuidex
void __cpuidex(INT32 CPUInfo[4], INT32 InfoType, INT32 ECXValue)
{
	if (NULL==CPUInfo)	return;
	_asm{
		// load. ��ȡ�������Ĵ���
		mov edi, CPUInfo;	// ׼����ediѰַCPUInfo
		mov eax, InfoType;
		mov ecx, ECXValue;
		// CPUID
		cpuid;
		// save. ���Ĵ������浽CPUInfo
		mov	[edi], eax;
		mov	[edi+4], ebx;
		mov	[edi+8], ecx;
		mov	[edi+12], edx;
	}
}
#endif	// #if _MSC_VER < 1600	// VS2010. ��˵VC2008 SP1֮���֧��__cpuidex

#if _MSC_VER < 1400	// VC2005��֧��__cpuid
void __cpuid(INT32 CPUInfo[4], INT32 InfoType)
{
	__cpuidex(CPUInfo, InfoType, 0);
}
#endif	// #if _MSC_VER < 1400	// VC2005��֧��__cpuid

#endif	// #if defined(_WIN64)

// ����CPUIDFIELD�ӻ������л�ȡ�ֶ�.
UINT32	getcpuidfield_buf(const INT32 dwBuf[4], CPUIDFIELD cpuf)
{
	return __GETBITS32(dwBuf[CPUIDFIELD_REG(cpuf)], CPUIDFIELD_POS(cpuf), CPUIDFIELD_LEN(cpuf));
}

// ����CPUIDFIELD��ȡCPUID�ֶ�.
UINT32	getcpuidfield(CPUIDFIELD cpuf)
{
	INT32 dwBuf[4];
	__cpuidex(dwBuf, CPUIDFIELD_FID(cpuf), CPUIDFIELD_FIDSUB(cpuf));
	return getcpuidfield_buf(dwBuf, cpuf);
}

// ȡ��CPU���̣�Vendor��
//
// result: �ɹ�ʱ�����ַ����ĳ��ȣ�һ��Ϊ12����ʧ��ʱ����0��
// pvendor: ���ճ�����Ϣ���ַ���������������Ϊ13�ֽڡ�
int cpu_getvendor(char* pvendor)
{
	INT32 dwBuf[4];
	if (NULL==pvendor)	return 0;
	// Function 0: Vendor-ID and Largest Standard Function
	__cpuid(dwBuf, 0);
	// save. ���浽pvendor
	*(INT32*)&pvendor[0] = dwBuf[1];	// ebx: ǰ�ĸ��ַ�
	*(INT32*)&pvendor[4] = dwBuf[3];	// edx: �м��ĸ��ַ�
	*(INT32*)&pvendor[8] = dwBuf[2];	// ecx: ����ĸ��ַ�
	pvendor[12] = '\0';
	return 12;
}

// ȡ��CPU�̱꣨Brand��
//
// result: �ɹ�ʱ�����ַ����ĳ��ȣ�һ��Ϊ48����ʧ��ʱ����0��
// pbrand: �����̱���Ϣ���ַ���������������Ϊ49�ֽڡ�
int cpu_getbrand(char* pbrand)
{
	INT32 dwBuf[4];
	if (NULL==pbrand)	return 0;
	// Function 0x80000000: Largest Extended Function Number
	__cpuid(dwBuf, 0x80000000);
	if (dwBuf[0] < 0x80000004)	return 0;
	// Function 80000002h,80000003h,80000004h: Processor Brand String
	__cpuid((INT32*)&pbrand[0], 0x80000002);	// ǰ16���ַ�
	__cpuid((INT32*)&pbrand[16], 0x80000003);	// �м�16���ַ�
	__cpuid((INT32*)&pbrand[32], 0x80000004);	// ���16���ַ�
	pbrand[48] = '\0';
	return 48;
}


// �Ƿ�֧��MMXָ�
BOOL	simd_mmx(BOOL* phwmmx)
{
	const INT32	BIT_D_MMX = 0x00800000;	// bit 23
	BOOL	rt = FALSE;	// result
	INT32 dwBuf[4];

	// check processor support
	__cpuid(dwBuf, 1);	// Function 1: Feature Information
	if ( dwBuf[3] & BIT_D_MMX )	rt=TRUE;
	if (NULL!=phwmmx)	*phwmmx=rt;

	// check OS support
	if ( rt )
	{
#if defined(_WIN64)
		// VC��������֧��64λ�µ�MMX��
		rt=FALSE;
#else
		__try 
		{
			_mm_empty();	// MMX instruction: emms
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			rt=FALSE;
		}
#endif	// #if defined(_WIN64)
	}

	return rt;
}

// ���SSEϵ��ָ���֧�ּ���
int	simd_sse_level(int* phwsse)
{
	const INT32	BIT_D_SSE = 0x02000000;	// bit 25
	const INT32	BIT_D_SSE2 = 0x04000000;	// bit 26
	const INT32	BIT_C_SSE3 = 0x00000001;	// bit 0
	const INT32	BIT_C_SSSE3 = 0x00000100;	// bit 9
	const INT32	BIT_C_SSE41 = 0x00080000;	// bit 19
	const INT32	BIT_C_SSE42 = 0x00100000;	// bit 20
	int	rt = SIMD_SSE_NONE;	// result
	INT32 dwBuf[4];

	// check processor support
	__cpuid(dwBuf, 1);	// Function 1: Feature Information
	if ( dwBuf[3] & BIT_D_SSE )
	{
		rt = SIMD_SSE_1;
		if ( dwBuf[3] & BIT_D_SSE2 )
		{
			rt = SIMD_SSE_2;
			if ( dwBuf[2] & BIT_C_SSE3 )
			{
				rt = SIMD_SSE_3;
				if ( dwBuf[2] & BIT_C_SSSE3 )
				{
					rt = SIMD_SSE_3S;
					if ( dwBuf[2] & BIT_C_SSE41 )
					{
						rt = SIMD_SSE_41;
						if ( dwBuf[2] & BIT_C_SSE42 )
						{
							rt = SIMD_SSE_42;
						}
					}
				}
			}
		}
	}
	if (NULL!=phwsse)	*phwsse=rt;

	// check OS support
	__try 
	{
		__m128 xmm1 = _mm_setzero_ps();	// SSE instruction: xorps
		if (0!=*(int*)&xmm1)	rt = SIMD_SSE_NONE;	// ����Releaseģʽ�����Ż�ʱ�޳���һ�����
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		rt = SIMD_SSE_NONE;
	}

	return rt;
}

// ���AVXϵ��ָ���֧�ּ���.
int	simd_avx_level(int* phwavx)
{
	int	rt = SIMD_AVX_NONE;	// result

	// check processor support
	if (0!=getcpuidfield(CPUF_AVX))
	{
		rt = SIMD_AVX_1;
		if (0!=getcpuidfield(CPUF_AVX2))
		{
			rt = SIMD_AVX_2;
		}
	}
	if (NULL!=phwavx)	*phwavx=rt;

	// check OS support
	if (0!=getcpuidfield(CPUF_OSXSAVE))	// XGETBV enabled for application use.
	{
		UINT32 n = getcpuidfield(CPUF_XFeatureSupportedMaskLo);	// XCR0: XFeatureSupportedMask register.
		if (6==(n&6))	// XCR0[2:1] = ��11b�� (XMM state and YMM state are enabled by OS).
		{
			return rt;
		}
	}
	return SIMD_AVX_NONE;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int i;

	//__cpuidex(dwBuf, 0,0);
	//__cpuid(dwBuf, 0);
	//printf("%.8X\t%.8X\t%.8X\t%.8X\n", dwBuf[0],dwBuf[1],dwBuf[2],dwBuf[3]);

	cpu_getvendor(szBuf);
	printf("CPU Vendor:\t%s\n", szBuf);

	cpu_getbrand(szBuf);
	printf("CPU Name:\t%s\n", szBuf);

	BOOL bhwmmx;	// Ӳ��֧��MMX.
	BOOL bmmx;	// ����ϵͳ֧��MMX.
	bmmx = simd_mmx(&bhwmmx);
	printf("MMX: %d\t// hw: %d\n", bmmx, bhwmmx);

	int	nhwsse;	// Ӳ��֧��SSE.
	int	nsse;	// ����ϵͳ֧��SSE.
	nsse = simd_sse_level(&nhwsse);
	printf("SSE: %d\t// hw: %d\n", nsse, nhwsse);
	for(i=1; i<sizeof(simd_sse_names)/sizeof(simd_sse_names[0]); ++i)
	{
		if (nhwsse>=i)	printf("\t%s\n", simd_sse_names[i]);
	}

	// test SSE4A/AES/PCLMULQDQ
	printf("SSE4A: %d\n", getcpuidfield(CPUF_SSE4A));
	printf("AES: %d\n", getcpuidfield(CPUF_AES));
	printf("PCLMULQDQ: %d\n", getcpuidfield(CPUF_PCLMULQDQ));

	// test AVX
	int	nhwavx;	// Ӳ��֧��AVX.
	int	navx;	// ����ϵͳ֧��AVX.
	navx = simd_avx_level(&nhwavx);
	printf("AVX: %d\t// hw: %d\n", navx, nhwavx);
	for(i=1; i<sizeof(simd_avx_names)/sizeof(simd_avx_names[0]); ++i)
	{
		if (nhwavx>=i)	printf("\t%s\n", simd_avx_names[i]);
	}

	// test F16C/FMA/FMA4/XOP
	printf("F16C: %d\n", getcpuidfield(CPUF_F16C));
	printf("FMA: %d\n", getcpuidfield(CPUF_FMA));
	printf("FMA4: %d\n", getcpuidfield(CPUF_FMA4));
	printf("XOP: %d\n", getcpuidfield(CPUF_XOP));

	return 0;
}