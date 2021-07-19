#include <stdio.h>
#include <limits.h>

#include "translate.h"

static int count_higher_ones(unsigned char value) {
	int i = 0;
	while (value >> (CHAR_BIT-1 - i) & 1) {	/// 1 << (CHAR_BIT-1) & (value << i)	/// Verifica os bits de maior peso a 1 seguidos
		i++;
	}
	return i;
}

static int utf_8_length(unsigned char a[]) {
	int bytes = count_higher_ones(a[0]);
	if (bytes == 0) return 1;
	if (bytes > 4) return 4;
	return bytes;
}

static int translate(unsigned char sym[], char *res) {
	*res = ' ';
	char lookup_c3_range[] = {
		'a',  //  À
		'a',  //  Á
		'a',  //  Â
		'a',  //  Ã
		'a',  //  Ä
		'a',  //  Å
		' ',  //  Æ
		'c',  //  Ç
		'e',  //  È
		'e',  //  É
		'e',  //  Ê
		'e',  //  Ë
		'i',  //  Ì
		'i',  //  Í
		'i',  //  Î
		'i',  //  Ï
		'd',  //  Ð
		'n',  //  Ñ
		'o',  //  Ò
		'o',  //  Ó
		'o',  //  Ô
		'o',  //  Õ
		'o',  //  Ö
		' ',  //  ×
		' ',  //  Ø
		'u',  //  Ù
		'u',  //  Ú
		'u',  //  Û
		'u',  //  Ü
		'y',  //  Ý
		' ',  //  Þ
		' ',  //  ß
		'a',  //  à
		'a',  //  á
		'a',  //  â
		'a',  //  ã
		'a',  //  ä
		'a',  //  å
		' ',  //  æ
		'c',  //  ç
		'e',  //  è
		'e',  //  é
		'e',  //  ê
		'e',  //  ë
		'i',  //  ì
		'i',  //  í
		'i',  //  î
		'i',  //  ï
		'o',  //  ð
		'n',  //  ñ
		'o',  //  ò
		'o',  //  ó
		'o',  //  ô
		'o',  //  õ
		'o',  //  ö
		' ',  //  ÷
		' ',  //  ø
		'u',  //  ù
		'u',  //  ú
		'u',  //  û
		'u',  //  ü
		'y',  //  ý
		' ',  //  þ
		'y'  //  ÿ
	};
	
	int size = utf_8_length(sym);
	
	
	if ((sym[0] >= '0' && sym[0] <= '9') || (sym[0] >= 'a' && sym[0] <= 'z') || (sym[0] >= 'A' && sym[0] <= 'Z')) {	/// ASCII básico
		if (sym[0] >= 'A' && sym[0] <= 'Z') {
			sym[0] += 0x20;								/// Passa para minúsculo
		}
		*res = sym[0];
	}
	else if (size == 2 && sym[0] == 0xc3) {				/// Caractere a 2 bytes
		*res = lookup_c3_range[(int)sym[1] & 0x3f];
	}
	
	return size;
}

void translate_string(char src[], char dst[]) {
	char res;
	int indSrc = 0;
	int indDst = 0;

	while (src[indSrc] != 0) {
		indSrc += translate((unsigned char*)&src[indSrc], &res);	/// Transforma cada caractere para minúsculo com o código ASCII básio correspondente
		dst[indDst++] = res;
	}
}
