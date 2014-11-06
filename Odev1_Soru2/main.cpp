#include <stdio.h>
#include <stdlib.h> // tip dönüşümleri için...
#include <ctype.h> // girilen değerin sayısal mı harf mi olduğunu kontrol etmek için...

void main ()
{
	int girilenSayi, cozumlenecekSayi, basamakSayisi, binlerBasamagi, yuzlerBasamagi, onlarBasamagi, birlerBasamagi;	
	char girilenSayiStr[10];

	do
	{
		printf("Cozumlenmesini istediginiz 4 basamkli bir sayi giriniz: ");
		scanf("%s", &girilenSayiStr);

		if (isdigit(girilenSayiStr[0])) //isdigit -> Check if character is decimal digit... Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9 
		{
			girilenSayi = atoi(girilenSayiStr); //atoi -> convert string to int (function)
		}
		// isalpha -> Check if character is alphabetic (function)
		// isalnum -> Check if character is alphanumeric (function)
		else if (isalpha(girilenSayiStr[0]) || isalnum(girilenSayiStr[0]))
		{
			printf("Girilen deger, sadece sayilardan olusmalidir! Girilen deger harflere kadar degerlendirilir!\n");
		}
		
		cozumlenecekSayi = girilenSayi;
		basamakSayisi = 0;
		while (girilenSayi > 0)
		{
			basamakSayisi++;
			girilenSayi /= 10;
		}
	
		printf("Girilen sayi, %d basamaklidir.\n", basamakSayisi);
	}
	while (basamakSayisi != 4);

	// Basamak sayısı sabit olarak verildiğinden aşağıdaki matematiksel çözümü tercih ettim.

	// Binler basamağı
	binlerBasamagi = cozumlenecekSayi/1000;
	// Yüzler basamağı
	cozumlenecekSayi = cozumlenecekSayi - (binlerBasamagi * 1000);
	yuzlerBasamagi = cozumlenecekSayi/100;
	// Onlar basamağı
	cozumlenecekSayi = cozumlenecekSayi - (yuzlerBasamagi * 100);
	onlarBasamagi = cozumlenecekSayi/10;
	//Birler basamağı
	cozumlenecekSayi = cozumlenecekSayi - (onlarBasamagi * 10);
	birlerBasamagi = cozumlenecekSayi;

	printf("\n%d tane binlik sayi,\n%d tane yuzluk sayi,\n%d tane onluk sayi,\n%d tane birlik sayi vardir\n\n", binlerBasamagi, yuzlerBasamagi, onlarBasamagi, birlerBasamagi);
}
