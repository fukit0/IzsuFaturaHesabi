#include <stdio.h>
#include <stdlib.h>

//Abone koduna gore abone turunu yazdiran fonksiyon
void abone_turu_yaz(int abone_kod)
{
    switch(abone_kod)
    {
        case 1:printf("Abone tipi: Konut\n"); break;
        case 2:printf("Abone tipi: Isyeri\n"); break;
        case 3:printf("Abone tipi: Kamu Kurumu\n"); break;
        case 4:printf("Abone tipi: Turistik Tesis\n"); break;
    }
}

int main()
{

    int abone_kod,gun_sayisi,ilk_sayac,son_sayac,tuketim,top_abone,tutar_max_kod,atik_max_kod,tutar_max_tuk,atik_max_tuk;
    //tutar_max_kod: en yuksek su tuketim ucreti icin o abonenin kodunu tutuyor
    //atik_max_kod: en yuksek atik su ucreti icin o abonenin kodunu tutuyor
    //tutar_max_tuk: en yuksek su tuketim ucreti icin o abonenin tuketimini tutuyor
    //atik_max_tuk: en yuksek atik su ucreti icin o abonenin tuketimini tutuyor

    int tip_1=0,tip_2=0,tip_3=0,tip_4=0,tip1_kademe1_alti=0,tip2_kademe1_ustu=0;

    int gun_sayisi1=0,gun_sayisi2=0,gun_sayisi3=0,gun_sayisi4=0;

    int top_tuketim=0,top_tuketim1=0,top_tuketim2=0,top_tuketim3=0,top_tuketim4=0;

    float ust_sinir1,ust_sinir2,atik_su,kdv,top_tutar;
    //ust_sinir1 ve ust_sinir2 degiskenleri gune gore belirlenen kademe sinirlari

    float tutar,tutar_1=0,tutar_2=0,tutar_3=0,tutar_4=0;

    float atik_su_top=0,kdv_top=0,gun_ort,gun_ort_max=0,tutar_max=0,atik_su_max=0;


    char sorgu='e';

    while(sorgu=='E' || sorgu=='e')
    {
        do
        {
            printf("Abone tipi kodu (1,2,3,4):\t");
            scanf("%d",&abone_kod);
        }
        while(abone_kod!=1 && abone_kod!=2 && abone_kod!=3 && abone_kod!=4);

        do
        {
            printf("Onceki sayac degeri: ");
            scanf("%d",&ilk_sayac);
        }
        while(ilk_sayac<0);

        do
        {
            printf("Simdiki sayac degeri: ");
            scanf("%d",&son_sayac);
        }
        while(son_sayac<ilk_sayac);

        tuketim=son_sayac-ilk_sayac;
        top_tuketim=top_tuketim+tuketim;

        do
        {
            printf("Gun sayisi: ");
            scanf("%d",&gun_sayisi);
        }
        while(gun_sayisi<=0);

        printf("-----------------------------------\n");

        switch(abone_kod)
        {
            case 1:

                tip_1++;

                ust_sinir1=(float)13*gun_sayisi/30;
                ust_sinir2=(float)20*gun_sayisi/30;

                if(tuketim<=ust_sinir1)
                {
                    tip1_kademe1_alti++;

                    tutar=tuketim*2.24;
                }
                else
                {
                    if(tuketim<=ust_sinir2)
                    {
                        tutar=ust_sinir1*2.24+(tuketim-ust_sinir1)*5.78;
                    }
                    else
                    {
                        tutar=ust_sinir1*2.24+(ust_sinir2-ust_sinir1)*5.78+(tuketim-ust_sinir2)*9.33;
                    }
                }

                atik_su=tuketim*1.91;
                kdv=(tutar+atik_su)*0.08;

                top_tuketim1=top_tuketim1+tuketim;
                tutar_1=tutar_1+tutar;
                gun_sayisi1=gun_sayisi1+gun_sayisi;

                gun_ort=(float)tuketim/gun_sayisi;

                if(gun_ort>gun_ort_max)
                {
                    gun_ort_max=gun_ort;
                }
                abone_turu_yaz(abone_kod);break;

            case 2:

                tip_2++;

                ust_sinir1=(float)10*gun_sayisi/30;

                if(tuketim<=ust_sinir1)
                {
                    tutar=tuketim*7.71;
                }
                else
                {
                    tip2_kademe1_ustu++;

                    tutar=ust_sinir1*7.71+(tuketim-ust_sinir1)*8.88;
                }

                atik_su=tuketim*3.79;
                kdv=(tutar+atik_su)*0.08;

                top_tuketim2=top_tuketim2+tuketim;
                tutar_2=tutar_2+tutar;
                gun_sayisi2=gun_sayisi2+gun_sayisi;

                abone_turu_yaz(abone_kod);break;

            case 3:

                tip_3++;

                tutar=tuketim*6.64;
                atik_su=tuketim*2.56;
                kdv=(tutar+atik_su)*0.08;

                top_tuketim3=top_tuketim3+tuketim;
                tutar_3=tutar_3+tutar;
                gun_sayisi3=gun_sayisi3+gun_sayisi;

                abone_turu_yaz(abone_kod);break;

            case 4:

                tip_4++;

                tutar=tuketim*5.78;
                atik_su=tuketim*1.91;
                kdv=(tutar+atik_su)*0.08;

                top_tuketim4=top_tuketim4+tuketim;
                tutar_4=tutar_4+tutar;
                gun_sayisi4=gun_sayisi4+gun_sayisi;

                abone_turu_yaz(abone_kod);break;

        }

        top_tutar=tutar+atik_su+kdv;

        if(tutar>tutar_max)
        {
            tutar_max=tutar;
            tutar_max_tuk=tuketim;
            tutar_max_kod=abone_kod;
        }

        if(atik_su>atik_su_max)
        {
            atik_su_max=atik_su;
            atik_max_tuk=tuketim;
            atik_max_kod=abone_kod;
        }

        printf("Su tuketim miktari: %d ton\n",tuketim);
        printf("Su tuketim ucreti: %.2f TL\n",tutar);
        printf("Atik su ucreti: %.2f TL\n",atik_su);
        printf("KDV tutari: %.2f TL\n",kdv);
        printf("Fatura tutari: %.2f TL\n\n",top_tutar);

        do
        {
            printf("Baska abone var mi? (E,e,H,h)\t");
            fflush(stdin);
            scanf("%c",&sorgu);
        }
        while(sorgu!='E' && sorgu!='e' && sorgu!='H' && sorgu!='h');

    atik_su_top=atik_su_top+atik_su;
    kdv_top=kdv_top+kdv;

    }

    top_abone=tip_1+tip_2+tip_3+tip_4;

    printf("1)");
                printf("\nAbone tipi   Abone sayisi    Abone yuzdesi    Gunluk ortalama su tuketimi \n");
                printf("----------   ------------    -------------    --------------------------- \n");
                printf("Konut               %d             %.2f                 %.2f ton\n",tip_1,(float)100*tip_1/top_abone,(float)top_tuketim1/gun_sayisi1);
                printf("Isyeri              %d             %.2f                 %.2f ton\n",tip_2,(float)100*tip_2/top_abone,(float)top_tuketim2/gun_sayisi2);
                printf("Kamu Kurumu         %d             %.2f                 %.2f ton\n",tip_3,(float)100*tip_3/top_abone,(float)top_tuketim3/gun_sayisi3);
                printf("Turistik Tesis      %d             %.2f                 %.2f ton\n",tip_4,(float)100*tip_4/top_abone,(float)top_tuketim4/gun_sayisi4);


    printf("\n2)\n");
                printf("Aylik su tuketimi, 1. kademeyi asmayan komut abonelerinin:\n");
                printf("Sayisi: %d\n",tip1_kademe1_alti);
                printf("Yuzdesi: %.2f\n\n",(float)100*tip1_kademe1_alti/tip_1);


    printf("\n3)\n");
                printf("Aylik su tuketimi, 1. kademeyi asan isyeri abonelerinin:\n");
                printf("Sayisi: %d\n",tip2_kademe1_ustu);
                printf("Yuzdesi: %.2f\n",(float)100*tip2_kademe1_ustu/tip_2);


    printf("\n4)\n");
                printf("Gunluk ortalama su tuketim miktari en yuksek olan konut tipi abonenin gunluk ortalama su tuketim miktari: %.2f ton\n",gun_ort_max);


    printf("\n5)\n");
                printf("Aylik su tuketim ucreti en yuksek olan abonenin:\n");
                abone_turu_yaz(tutar_max_kod);
                printf("Aylik su tuketim miktari: %d ton\n",tutar_max_tuk);
                printf("Odedigi aylik su tuketim ucreti: %.2f TL\n",tutar_max);


    printf("\n6)\n");
                printf("Aylik atik su ucreti en yuksek olan abonenin:\n");
                abone_turu_yaz(atik_max_kod);
                printf("Aylik su tuketim miktari: %d ton\n",atik_max_tuk);
                printf("Odedigi aylik atik su ucreti: %.2f TL\n",atik_su_max);


    printf("\n7)");
                printf("\nAbone Tipi     Toplam Su Tuketim Miktari\n");
                printf("----------     -------------------------\n");
                printf("Konut               %d ton\n",top_tuketim1);
                printf("Isyeri              %d ton\n",top_tuketim2);
                printf("Kamu Kurumu         %d ton\n",top_tuketim3);
                printf("Turistik Tesis      %d ton\n",top_tuketim4);
                printf("\nToplam            \t%d ton\n",top_tuketim);


    printf("\n8)");
                printf("\nAbone Tipi     Toplam Su Tuketim Ucreti\n");
                printf("----------     ------------------------\n");
                printf("Konut               %.2f TL\n",tutar_1);
                printf("Isyeri              %.2f TL\n",tutar_2);
                printf("Kamu Kurumu         %.2f TL\n",tutar_3);
                printf("Turistik Tesis      %.2f TL\n",tutar_4);
                printf("\nToplam            \t%.2f TL\n",tutar_1+tutar_2+tutar_3+tutar_4);


    printf("\n9)\n");
                printf("Tum abonelerden elde edilen aylik toplam atik su ucreti: %.2f TL\n",atik_su_top);


    printf("\n10)\n");
                printf("Devlete odenen aylik toplam KDV tutari: %.2f TL\n\n",kdv_top);

    return 0;
}
