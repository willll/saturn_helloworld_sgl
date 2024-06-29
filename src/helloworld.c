#include	"sgl.h"

#define		SystemWork		0x060ffc00		/* System Variable Address */
#define		SystemSize		(0x06100000-0x060ffc00)		/* System Variable Size */
/* sl.lnk �Ŏw�肵��.bss�Z�N�V�����̊J�n�A�I���V���{�� */
extern Uint32 _bss_start, _bss_end;

int main()
{
  Uint8	*dst;
	Uint32	i;

	/* 1.Zero Set .bss Section */
	for( dst = (Uint8 *)&_bss_start; dst < (Uint8 *)&_bss_end; dst++ ) {
		*dst = 0;
	}
	/* 2.ROM has data at end of text; copy it. */

	/* 3.SGL System Variable Clear */
	for( dst = (Uint8 *)SystemWork, i = 0;i < SystemSize; i++) {
		*dst = 0;
	}

  slInitSystem(TV_352x224,NULL,1);

	slZdspLevel(7);

	slPrint("Hello World !", slLocate(0,0));

	while(-1){
		slSynch();
  }

    return 0;
}
