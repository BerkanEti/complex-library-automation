#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef _WIN32            //sleep() icin kutuphaneler
#include <Windows.h>
#else
#include <unistd.h>
#endif  

#ifdef _WIN32           //clearAll() icin kutuphaneler
	void clearAll(){
		system("cls");
	}
#endif

#ifdef __APPLE__
	void clearAll(){
		system("clear");
	}
#endif

typedef struct Ogrenci{
    char ogrId[9] ;
    char ad[30] ;
    char soyad[30] ;
    int puan ;
    struct Ogrenci* next;
    struct Ogrenci* prev;

}OGRENCI ;

typedef struct Yazar{
    int yazarID ;
    char yazarAd[30] ;
    char yazarSoyad[30] ;
    struct Yazar*next ;
}YAZAR ;

typedef struct KitapOrnek{
    char EtiketNo[20] ;
    char Durum[9] ;
    struct KitapOrnek *next ;

}KITAPORNEK ;

typedef struct Kitap{
    char kitapAdi[30] ;
    char ISBN[14] ;
    int adet ;
    struct Kitap *next ;
    struct KitapOrnek *head ;

}KITAP ;

typedef struct KitapYazar{
    char ISBN[14] ;
    int yazarID ;

}KITAPYAZAR ;

typedef struct Tarih{
    unsigned int gun:5 ;
    unsigned int ay:4 ;
    unsigned int yil:12 ;

}Tarih ;

typedef struct KitapOdunc{
    char EtiketNo[20] ;
    char ogrID[9] ;
    unsigned int islemTipi:1 ;
    struct Tarih islemTarihi ;
}KITAPODUNC ;


void ogrenciVeriAl(OGRENCI**) ;
void ogrenciVeriYaz(OGRENCI*) ;
int ogrenciKontrol(OGRENCI* , char* ) ;
OGRENCI* ogrenciOlustur() ;
void ogrenciEkle(OGRENCI** , OGRENCI *) ;
void ogrenciGuncelle(OGRENCI*) ;
void ogrenciSil(OGRENCI** ) ;
OGRENCI* ogrenciIdAra(OGRENCI*  , char*  ) ;
OGRENCI* ogrenciAdSoyadAra(OGRENCI* , char* ,char* ) ;
OGRENCI* ogrenciAdVeyaSoyadAra(OGRENCI*  , char*  ,int  (*f)(OGRENCI* , char*)) ;
int ogrenciAdKontrol(OGRENCI* , char*  );
int ogrenciSoyadKontrol(OGRENCI* , char*  );
OGRENCI* ogrenciBul(OGRENCI* ,int*  , int ) ;

void ogrencileriListele(OGRENCI* ) ;
void ogrenciGoruntule(OGRENCI* , KITAP* , KITAPODUNC** , int ) ;
void kitapTeslimEtmemisOgrenciler(OGRENCI* ,KITAP* , KITAPODUNC**  , int ) ;
void cezaliOgrenciler(OGRENCI* ) ; 
void ogrenciGuncelle(OGRENCI*) ;

void kitapVeriAl(KITAP**) ;
void kitapVeriYaz(KITAP*);
int kitapKontrol(KITAP* , char* ) ;
KITAP* kitapOlustur() ;
void kitapEkle(KITAP** , KITAP *) ;
void kitapSil(KITAP** , KITAPYAZAR*** , int* , KITAPODUNC*** , int* ) ;
void kitapGuncelle(KITAP*  , KITAPODUNC**  , int , KITAPYAZAR**  , int ) ;
KITAP* kitapAra(KITAP* ,char* ,int (*f)(KITAP* , char*)) ;
int kitapISBNAra(KITAP* , char* ) ;
int kitapAdiAra(KITAP* , char* ) ;
KITAP* kitapBul(KITAP*  , int*  , int ) ;
char* isbnBul(char* ) ;
void kitapGoruntule(YAZAR* , KITAP* ,KITAPYAZAR** , int );
void kitapRaftakileriListele(KITAP*) ;

void kitapOrnekOlustur(KITAP**, int);
void kitapOrnekYazdir(KITAP*);

void yazarVeriAl(YAZAR** , int*) ;  
void yazarVeriYaz(YAZAR*) ; 
YAZAR* yazarOlustur() ;
void yazarEkle(YAZAR** , YAZAR *) ;
void yazarGuncelle(YAZAR* ) ;
YAZAR* yazarIdAra(YAZAR* , int) ;
YAZAR* yazarAdSoyadAra(YAZAR*  , char*  , char*  ) ;
YAZAR* yazarAdVeyaSoyadAra(YAZAR*  , char* c ,int  (*f)(YAZAR* , char*)) ;
int yazarAdKontrol(YAZAR* , char*  );
int yazarSoyadKontrol(YAZAR* , char*  );
YAZAR* yazarBul(YAZAR* ,int*  , int ) ;
void yazarSil(YAZAR** , KITAPYAZAR**, int) ;
void yazarGoruntule(YAZAR* , KITAPYAZAR** , int , KITAP* );

void kitapYazarAlanAyir(KITAPYAZAR***  , int* ) ;
void kitapYazarVeriAl(KITAPYAZAR*** , int* ) ;
void kitapYazarVeriYaz(KITAPYAZAR** , int ) ;
void kitapYazarEslestir(KITAPYAZAR*** , int* , KITAP* , YAZAR* ) ;
void kitapYazariYaz(YAZAR* , KITAPYAZAR**, int, char*) ;
void kitapYazariGuncelle(KITAP* , YAZAR* , KITAPYAZAR**  , int ) ;

void kitapOduncAlanAyir(KITAPODUNC***  , int* ) ;
void kitapOduncVeriAl(KITAPODUNC*** ,KITAP* ,OGRENCI*, int* ) ;
void kitapOduncVeriYaz(KITAPODUNC**, int ) ;
int kitapTarihKontrolu(KITAPODUNC**  , int  ) ;
void kitapOduncIslemi(OGRENCI* ,KITAP* , KITAPODUNC***  , int * ,int (*f)(OGRENCI* ,KITAP* , KITAPODUNC*** , int* , int ,int ,int)) ;
int kitapOduncAlma(OGRENCI* ,KITAP* , KITAPODUNC***  , int* , int ,int ,int ) ;
int kitapTeslimEtme(OGRENCI* ,KITAP* , KITAPODUNC***  , int* , int ,int ,int ) ;
void kitapOduncZamaniGecmisler(KITAPODUNC** ,KITAP*  ,int ) ;

void butunKitapYazarGoruntule(KITAPYAZAR** , int ) ;
void butunOduncGoruntule(KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci) ;
void butunKitapGoruntule(KITAP*) ;
void butunYazarGoruntule(YAZAR* head ) ;

void bekle(int ) ;
void menuyeDon() ;

void ogrenciBellekTemizle(OGRENCI* ) ;
void kitapBellekTemizle(KITAP* ) ;
void yazarBellekTemizle(YAZAR* ) ;
void kitapYazarBellekTemizle(KITAPYAZAR** , int ) ;
void kitapOduncBellekTemizle(KITAPODUNC** , int ) ;



int main(){
    int option=1;
    int yazarSayaci = 0  ;
    
    OGRENCI *headOgrenci = NULL ;
    YAZAR *headYazar = NULL ;
    KITAP *headKitap = NULL ;
    KITAPYAZAR **kitapYazarData = NULL ;
    int kitapYazarDataSayaci = 0 ;

    KITAPODUNC **kitapOduncData = NULL ;
    int kitapOduncDataSayaci = 0 ;

    ogrenciVeriAl(&headOgrenci) ;
    yazarVeriAl(&headYazar,&yazarSayaci) ;
    kitapVeriAl(&headKitap) ;
    kitapYazarVeriAl(&kitapYazarData,&kitapYazarDataSayaci) ;
    kitapOduncVeriAl(&kitapOduncData,headKitap,headOgrenci,&kitapOduncDataSayaci) ;
    
    while(option != 0){
        printf("\n\nOgrenci Islemleri\n"
        "\t1)Ogrenci Ekle\n"
        "\t2)Ogrenci Sil\n"
        "\t3)Ogrenci Bilgileri Guncelle\n"
        "\t4)Ogrenci Bilgisi Goruntule\n"
        "\t5)Kitap Teslim Etmemis Ogrencileri Listele\n"
        "\t6)Cezali Ogrencileri Listele\n"
        "\t7)Tum Ogrencileri Listele\n"
        "\t8)Kitap Odunc Al\n"
        "\t9)Kitap Teslim Et\n"
        "\nKitap Islemleri\n"
        "\t10)Kitap Ekle\n"
        "\t11)Kitap Sil\n"
        "\t12)Kitap Bilgileri Guncelle\n"
        "\t13)Kitap Bilgisi Goruntule\n"
        "\t14)Raftaki Kitaplari Listele\n"
        "\t15)Zamaninda Teslim Edilmeyen Kitaplari Listele\n"
        "\t16)Kitap-Yazar Eslestir\n"
        "\t17)Kitabin Yazarini Guncelle\n"
        "\nYazar Islemleri\n"
        "\t18)Yazar Ekle\n"
        "\t19)Yazar Sil\n"
        "\t20)Yazar Bilgileri Guncelle\n"
        "\t21)Yazar Bilgisi Goruntule\n"
        "\nBazi Genel Goruntuleme Islemleri\n"
        "\t22)Tum Kitaplar\n"
        "\t23)Tum Yazarlar\n"
        "\t24)Kitap-Yazar Eslestirmeleri\n"
        "\t25)Kitap Odunc Islemleri\n"
        "\n0) Cikmak icin "
        "\nYapmak Istediginiz Islem :");

        scanf("%d",&option);
        switch (option)
        {

        case 0:
            printf("\n Cikis Yapiliyor");
            bekle(1) ;
            printf("\nDosyalar Guncelleniyor.."
            "\nBellek Temizleniyor..") ;
            bekle(2) ;
            break;

        case 1:
            ogrenciEkle(&headOgrenci,ogrenciOlustur()) ; 
            bekle(3) ; 
            clearAll() ;  
            //ogrenciVeriYaz(headOgrenci) ;   
            break;

        case 2:
            ogrenciSil(&headOgrenci) ;
            bekle(3) ;
            clearAll() ;
            //ogrenciVeriYaz(headOgrenci) ;     
            break;
        
        case 3:
            ogrenciGuncelle(headOgrenci) ;
            bekle(3) ;
            clearAll() ;
            //ogrenciVeriYaz(headOgrenci) ;
            break;

        case 4:
            ogrenciGoruntule(headOgrenci,headKitap,kitapOduncData,kitapOduncDataSayaci) ;
            menuyeDon() ;
            break;
        
        case 5:
            kitapTeslimEtmemisOgrenciler(headOgrenci,headKitap,kitapOduncData,kitapOduncDataSayaci) ;
            menuyeDon() ;
            break;

        case 6:
            cezaliOgrenciler(headOgrenci) ;
            menuyeDon() ;
            break;
        
        case 7:
            ogrencileriListele(headOgrenci) ;
            menuyeDon() ; 
            break;
        
        case 8:
            kitapOduncIslemi(headOgrenci,headKitap,&kitapOduncData,&kitapOduncDataSayaci,kitapOduncAlma) ;
            bekle(3) ;
            clearAll() ;
            //kitapOduncVeriYaz(kitapOduncData,kitapOduncDataSayaci) ;
            break;
        
        case 9:
            kitapOduncIslemi(headOgrenci,headKitap,&kitapOduncData,&kitapOduncDataSayaci,kitapTeslimEtme) ;
            bekle(3) ;
            clearAll() ;
            //kitapOduncVeriYaz(kitapOduncData,kitapOduncDataSayaci) ;
            break;

        case 10:
            kitapEkle(&headKitap,kitapOlustur()) ;
            bekle(3) ;
            clearAll() ;
            //kitapVeriYaz(headKitap) ;
            break;

        case 11:
            kitapSil(&headKitap,&kitapYazarData,&kitapYazarDataSayaci,&kitapOduncData,&kitapOduncDataSayaci) ;
            bekle(3) ;
            clearAll() ;
            //kitapVeriYaz(headKitap) ;
            //kitapYazarVeriYaz(kitapYazarData,kitapYazarDataSayaci);
            //kitapOduncVeriYaz(kitapOduncData,kitapOduncDataSayaci) ;
            break;

        case 12:
            kitapGuncelle(headKitap,kitapOduncData,kitapOduncDataSayaci,kitapYazarData,kitapYazarDataSayaci) ;
            bekle(3) ;
            clearAll() ;
            break;

        case 13:
            kitapGoruntule(headYazar,headKitap,kitapYazarData,kitapYazarDataSayaci) ;
            menuyeDon() ;
            break;

        case 14:
            kitapRaftakileriListele(headKitap) ;
            menuyeDon() ;
            break;   

        case 15:
            kitapOduncZamaniGecmisler(kitapOduncData,headKitap,kitapOduncDataSayaci) ;
            menuyeDon() ;
            break;

        case 16:
            kitapYazarEslestir(&kitapYazarData,&kitapYazarDataSayaci,headKitap,headYazar) ;
            bekle(3) ;
            clearAll() ;
            //kitapYazarVeriYaz(kitapYazarData,kitapYazarDataSayaci);
            break;

        case 17:
            kitapYazariGuncelle(headKitap,headYazar,kitapYazarData,kitapYazarDataSayaci) ;
            bekle(3) ;
            clearAll() ;
            break;

        case 18:
            yazarEkle(&headYazar,yazarOlustur(&yazarSayaci)) ;
            bekle(3) ;
            clearAll() ;
            //yazarVeriYaz(headYazar) ;
            break; 

        case 19:
            yazarSil(&headYazar,kitapYazarData,kitapYazarDataSayaci) ;
            bekle(3) ;
            clearAll() ;
            //yazarVeriYaz(headYazar) ;
            //kitapYazarVeriYaz(kitapYazarData,kitapYazarDataSayaci);
            break;

        case 20:
            yazarGuncelle(headYazar) ;
            bekle(3) ;
            clearAll() ;
            break;

        case 21:
            yazarGoruntule(headYazar,kitapYazarData,kitapYazarDataSayaci,headKitap) ;
            menuyeDon() ;
            break;

        case 22:
            butunKitapGoruntule(headKitap) ;
            menuyeDon() ;
            break;

        case 23 :
            butunYazarGoruntule(headYazar) ;
            menuyeDon() ;
            break;

        case 24:
            butunKitapYazarGoruntule(kitapYazarData,kitapYazarDataSayaci) ;
            menuyeDon() ;
            break;

        case 25:
            butunOduncGoruntule(kitapOduncData,kitapOduncDataSayaci) ;
            menuyeDon() ;
            break;

        default:
            printf("\nGecerli bir islem giriniz") ;
            break;
        }

        
    }
 
    ogrenciVeriYaz(headOgrenci) ;
    kitapVeriYaz(headKitap) ;
    yazarVeriYaz(headYazar) ;
    kitapYazarVeriYaz(kitapYazarData,kitapYazarDataSayaci);
    kitapOduncVeriYaz(kitapOduncData,kitapOduncDataSayaci) ;
 
    ogrenciBellekTemizle(headOgrenci) ;
    kitapBellekTemizle(headKitap) ;
    yazarBellekTemizle(headYazar) ;
    kitapYazarBellekTemizle(kitapYazarData,kitapYazarDataSayaci) ;
    kitapOduncBellekTemizle(kitapOduncData,kitapOduncDataSayaci) ;

    return 0;
}

void ogrenciVeriAl(OGRENCI** head){
    FILE* ptr ;
    
    int puan ;
    
    ptr = fopen("Ogrenciler.csv","r") ;

    if(ptr == NULL){
        printf("Error ! ") ;
        exit(-1);
    }

    while(!feof(ptr)){

        OGRENCI* p ;
        p = (OGRENCI*) malloc(sizeof(OGRENCI)) ;

        if(p == NULL){
            printf("Error ! ") ;
            exit(-1) ;
        }

        fscanf(ptr,"%[^,],%[^,],%[^,],%d ",p->ogrId,p->ad,p->soyad,&puan) ;
        
        p->puan = puan ; 
        p->next = NULL ;
        p->prev = NULL ;
        ogrenciEkle(head,p) ; 

    }
    fclose(ptr) ;
}

void ogrenciVeriYaz(OGRENCI* head){
    
    OGRENCI* p ;
    FILE* ptr ;
    ptr = fopen("Ogrenciler.csv","w+") ;
    for(p=head; p != NULL ; p=p->next){
        fprintf(ptr,"%s,%s,%s,%d",p->ogrId,p->ad,p->soyad,p->puan) ;
        if(p->next != NULL){
            fprintf(ptr,"\n");
        }
    }
    fclose(ptr) ;
}


OGRENCI* ogrenciOlustur(){
    OGRENCI *temp ;
    temp = (OGRENCI*) malloc(sizeof(OGRENCI)) ;

    int cntrl = 1 ;

    if(temp == NULL){
        printf("Error ! ") ;
        exit(-1) ;
    }

    while(cntrl){
        printf("\nID :") ; scanf("%s",temp->ogrId) ;
        if(strlen(temp->ogrId) == 8){
            cntrl = 0 ;
        }
        else{
            printf("\nID 8 haneli olmalidir ! ") ;
        }
    }

    printf("Ad :") ; scanf("%s",temp->ad) ;
    printf("Soyad :") ; scanf("%s",temp->soyad) ;

    temp->puan = 100 ;

    temp->next = NULL ;
    temp->prev = NULL ;

    return temp ;
}

int ogrenciKontrol(OGRENCI* head , char ogrID[]){
    OGRENCI* p ;
    for(p=head; p != NULL ; p=p->next){
        if(strcmp(p->ogrId,ogrID) == 0){
            return 1 ;
        }
    }
    return 0 ;
}

void ogrenciEkle(OGRENCI **head , OGRENCI *yeniOgrenci){
    OGRENCI* p ;

    if(ogrenciKontrol(*head,yeniOgrenci->ogrId)){
        printf("\n UYARI : Ayni ID'ye sahip ogrenci bulunuyor !") ;
        return ;
    }

    if(*head == NULL){
        *head = yeniOgrenci ;
        return ;
    }

    for(p=*head ; p->next!= NULL ; p=p->next) ;

    p->next = yeniOgrenci ;
    (p->next)->prev = p ;
}

void ogrenciSil(OGRENCI** head ){
    OGRENCI* p ;

    int op = 0 ;

    char ogrId[9] ;
    char ad[30] , soyad[30] ;

    p = ogrenciBul((*head),&op,0) ;
    if(p == NULL){
        printf("\nOgrenci Bulunamadi\n") ;
        return ;
    }

    strcpy(ogrId,p->ogrId) ; strcpy(ad,p->ad) ; strcpy(soyad,p->soyad) ;
    while(p != NULL){
        printf("%s ID'li %s %s isimli ogrenci siliniyor...\n",p->ogrId,p->ad,p->soyad) ;
        if(p->prev == NULL){
            if(p->next == NULL){
                *head = NULL ;
            }
            else{
                *head = p->next ;
                (*head)->prev = NULL ;
            }
        }
        else if(p->next == NULL){
            (p->prev)->next = NULL ;
        }
        else{
            (p->prev)->next = p->next ;
            (p->next)->prev = p->prev ;
        }

        free(p) ;
        
        if(op== 2) p = ogrenciAdSoyadAra((*head),ad,soyad) ;
        else if(op== 3) p = ogrenciAdVeyaSoyadAra((*head),ad,ogrenciAdKontrol) ;
        else if(op== 4) p = ogrenciAdVeyaSoyadAra((*head),soyad,ogrenciSoyadKontrol) ;
        else p = NULL ;
       
        }
}

OGRENCI* ogrenciIdAra(OGRENCI* head , char* ogrID ){
    OGRENCI* temp ;
    for(temp=head ; temp != NULL ; temp=temp->next){
        if(strcmp(temp->ogrId,ogrID) == 0){
            return temp ;
        }
    }
    return NULL ;
}

OGRENCI* ogrenciAdSoyadAra(OGRENCI* p , char* ogrAd , char* ogrSoyad ){
    OGRENCI* temp ;
    for(temp=p ; temp != NULL ; temp=temp->next){
        if(strcmp(temp->ad,ogrAd) == 0 && strcmp(temp->soyad,ogrSoyad) == 0){
            return temp ;
        }
    }
    return NULL ;
}

OGRENCI* ogrenciAdVeyaSoyadAra(OGRENCI* headOgrenci , char* c ,int  (*f)(OGRENCI* , char*)){
    OGRENCI* p ;
    for(p=headOgrenci; p != NULL ; p=p->next){
        if(f(p,c)){
            return p ;
        }
    }
    return NULL ;
}

int ogrenciAdKontrol(OGRENCI* p  , char* c ){
    if(strcmp(p->ad,c) == 0){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

int ogrenciSoyadKontrol(OGRENCI* p , char* c ){
    if(strcmp(p->soyad,c) == 0){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

OGRENCI* ogrenciBul(OGRENCI* headOgrenci,int* op , int cntrl){
    OGRENCI* ogrenci ;
    char ogrID[9] , ad[30] , soyad[30] ;
    while((*op) == 0){
        printf("\n Ogrenci ID ile islem yapmak icin 1 \n Ad-Soyad ile islem yapmak icin 2 \n Sadece ad ile islem yapmak icin 3 \n Sadece soyadi ile islem yapmak icin 4 \n Secim :") ; scanf("%d",op) ;
        switch((*op)){
            case 1 :
                printf("\nOgrenci ID :") ; scanf("%s",ogrID) ;
                ogrenci = ogrenciIdAra(headOgrenci,ogrID) ;
                break ;
            case 2 :
                printf("\nOgrenci Ad :") ; scanf("%s",ad) ; printf("\nOgrenci Soyad :") ; scanf("%s",soyad) ;
                ogrenci = ogrenciAdSoyadAra(headOgrenci,ad,soyad) ;
                if(cntrl == 1 && ogrenci != NULL && ogrenciAdSoyadAra(ogrenci->next,ad,soyad) != NULL){
                    printf("\nAyni isim soyisimde birden fazla ogrenci var ! Lutfen farkli bir turde arama yapiniz.\n") ;
                    (*op) = 0 ;
                }
                break ;
            case 3 :
                printf("\nOgrenci Ad :") ; scanf("%s",ad) ;
                ogrenci = ogrenciAdVeyaSoyadAra(headOgrenci,ad,ogrenciAdKontrol) ;
                if(cntrl == 1 && ogrenci != NULL && ogrenciAdVeyaSoyadAra(ogrenci->next,ad,ogrenciAdKontrol) != NULL){
                    printf("\nAyni isimde birden fazla ogrenci var ! Lutfen farkli bir turde arama yapiniz.\n") ;
                    (*op) = 0 ;
                }
                break ;
            case 4 :
                printf("\nOgrenci Soyad :") ; scanf("%s",soyad) ;
                ogrenci = ogrenciAdVeyaSoyadAra(headOgrenci,soyad,ogrenciSoyadKontrol) ;
                if(cntrl == 1 && ogrenci != NULL && ogrenciAdVeyaSoyadAra(ogrenci->next,soyad,ogrenciSoyadKontrol) != NULL){
                    printf("\nAyni soyisimde birden fazla ogrenci var ! Lutfen farkli bir turde arama yapiniz.\n") ;
                    (*op) = 0 ;
                }
                break ;
            default :
                printf("\nHatali Secim\n") ;
                (*op) = 0 ;
                break ;
        }
    }
    return ogrenci ;
}

void ogrencileriListele(OGRENCI* head ){   
    OGRENCI* p ;

    if(head == NULL){
        printf("\nListe Bos ! \n"); 
        return ;
    }
    printf("\n-----TUM OGRENCILER------\n") ;
    for(p=head; p != NULL ; p=p->next){
        printf("\n%s %s  %s %d",p->ogrId,p->ad,p->soyad,p->puan) ;
    }
}
   
void ogrenciGuncelle(OGRENCI* head){
    OGRENCI* p ;
    int ogrPuan ;

    int op = 0 ;
    p = ogrenciBul(head,&op,1) ;
    if(p == NULL){
        printf("\nOgrenci Bulunamadi\n") ;
        return ;
    }

    printf("\nOgrenci simdiki ID : %s \nOgrenci simdiki Adi: %s \nOgrenci simdiki Soyadi : %s \nOgrenci simdiki Puani : %d \n\n",p->ogrId,p->ad,p->soyad,p->puan) ;
    printf("Ogrenci Yeni Adi : ") ; scanf("%s",p->ad) ;
    printf("Ogrenci Yeni Soyadi : ") ; scanf("%s",p->soyad) ;
    printf("Ogrenci Yeni Puan : ") ; scanf("%d",&ogrPuan) ; p->puan = ogrPuan ;

    printf("\nGuncelleme Basarili ! \n") ;
}

void ogrenciGoruntule(OGRENCI* headOgrenci , KITAP* headKitap , KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci){
    char ISBN[14] ;
    char ogrID[9] , ad[30] , soyad[30] ;

    int i ;
    int op = 0 ;
    int cntrl = 0 ;

    OGRENCI* ogrenci ;
    KITAP* kitap ;

    ogrenci = ogrenciBul(headOgrenci,&op,0) ;

    if(ogrenci == NULL){
        printf("\nOgrenci Bulunamadi\n") ;
        return ;
    }

    strcpy(ogrID,ogrenci->ogrId) ; strcpy(ad,ogrenci->ad) ; strcpy(soyad,ogrenci->soyad) ;
    while(ogrenci != NULL){
        printf("\n\nOgrenci ID : %s\n",ogrenci->ogrId) ;
        printf("Ogrenci Ad Soyad : %s %s\n",ogrenci->ad,ogrenci->soyad) ;
        printf("Ogrenci Puan : %d\n",ogrenci->puan) ;

        cntrl = 0 ;
        for(i = 0 ; i < kitapOduncDataSayaci ; i++){
            if(strcmp(kitapOduncData[i]->ogrID,ogrenci->ogrId) == 0){
                strcpy(ISBN,isbnBul(kitapOduncData[i]->EtiketNo)) ;
                kitap = kitapAra(headKitap,ISBN,kitapISBNAra) ;

                if(++cntrl == 1)printf("\n-----OGRENCININ KITAP HAREKETLERI-----\n") ;
                if(kitapOduncData[i]->islemTipi == 1){
                    printf("\n%d.%d.%d Tarihinde\n\"%s\" Isimli\n%s Etiket No'lu kitap teslim edilmistir.\n",kitapOduncData[i]->islemTarihi.gun,kitapOduncData[i]->islemTarihi.ay,kitapOduncData[i]->islemTarihi.yil,kitap->kitapAdi,kitapOduncData[i]->EtiketNo) ;
                }
                else if(kitapOduncData[i]->islemTipi == 0){
                     printf("\n%d.%d.%d Tarihinde\n\"%s\" Isimli\n%s Etiket No'lu kitap odunc alinmistir.\n",kitapOduncData[i]->islemTarihi.gun,kitapOduncData[i]->islemTarihi.ay,kitapOduncData[i]->islemTarihi.yil,kitap->kitapAdi,kitapOduncData[i]->EtiketNo) ;
                }   
            }
        }
        if(cntrl == 0)printf("\nOgrenci Kitap Odunc Alamamistir.\n") ;
        if(op == 1) ogrenci = NULL ;
        else if(op == 2) ogrenci = ogrenciAdSoyadAra(ogrenci->next,ad,soyad);
        else if(op == 3) ogrenci = ogrenciAdVeyaSoyadAra(ogrenci->next,ad,ogrenciAdKontrol) ;
        else ogrenci = ogrenciAdVeyaSoyadAra(ogrenci->next,soyad,ogrenciSoyadKontrol) ;
    }


}

void cezaliOgrenciler(OGRENCI* headOgrenci){
    OGRENCI* temp ;
    int ogr = 0 ;

    for(temp=headOgrenci;temp!=NULL;temp=temp->next){
        if(temp->puan < 0){
            printf("\nCezali Ogrenci ID : %s\n",temp->ogrId) ;
            printf("Cezali Ogrenci Ad Soyad : %s %s\n",temp->ad,temp->soyad) ;
            printf("Cezali Ogrenci Puan : %d\n",temp->puan) ;
            ogr++ ;
        }
    }

    if(ogr == 0) printf("\nCezali ogrenci bulunmamaktadir. \n") ;
}

void kitapTeslimEtmemisOgrenciler(OGRENCI* headOgrenci,KITAP* headKitap , KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci){
    int cntrl ;
    int ogr = 0 ;
    int i  ,j ;

    char ISBN[14] ;

    OGRENCI* ogrenci ;
    KITAP* kitap ;

    for(i=kitapOduncDataSayaci-1;i>=0;i--){
        if(kitapOduncData[i]->islemTipi == 0){
            cntrl = 0 ;
            for(j=i;j<kitapOduncDataSayaci;j++){
                if(strcmp(kitapOduncData[i]->ogrID,kitapOduncData[j]->ogrID) == 0 && strcmp(kitapOduncData[i]->EtiketNo,kitapOduncData[j]->EtiketNo) == 0){   
                    if(kitapOduncData[j]->islemTipi == 1)   cntrl = 1 ;
                    else    cntrl = 0 ;      
                }
            }    
            if(cntrl == 0){
                ogrenci = ogrenciIdAra(headOgrenci,kitapOduncData[i]->ogrID) ;

                strcpy(ISBN,isbnBul(kitapOduncData[i]->EtiketNo)) ;
                kitap = kitapAra(headKitap,ISBN,kitapISBNAra) ;

                printf("\nOgrenci ID : %s\n",ogrenci->ogrId) ;
                printf("Ogrenci Ad Soyad: %s %s\n",ogrenci->ad,ogrenci->soyad) ;
                printf("Teslim Edilmemis Kitap Adi : %s\n",kitap->kitapAdi) ;
                printf("Teslim Edilmemis Kitap Etiket Numarasi : %s\n", kitapOduncData[i]->EtiketNo);
                
                ogr++ ;
            }
        }
    }

    if(ogr == 0 ) printf("\nKitabini teslim etmemis ogrenci bulunmamaktadir \n") ;
}

void kitapVeriAl(KITAP** head){
    FILE* ptr ;
    ptr = fopen("Kitaplar.csv","r") ;
  
    int k ;

    if(ptr == NULL){
        printf("Error ! ") ;
        exit(-1);
    }

    while(!feof(ptr)){
        KITAP* p ;
        p = (KITAP*) malloc(sizeof(KITAP)) ;

        if(p == NULL){
            printf("Error ! ") ;
            exit(-1) ;
        }

        fscanf(ptr,"%[^,],%[^,],%d ",p->kitapAdi,p->ISBN,&k) ;
        p->adet = k ;
        p->next = NULL ;
        kitapOrnekOlustur(&p,k) ;
        kitapEkle(head,p) ;

    }
    fclose(ptr) ;
} 

void kitapVeriYaz(KITAP* head){
    KITAP* p ;
    FILE* ptr ;
    ptr = fopen("Kitaplar.csv","w+") ;
    for(p=head; p != NULL ; p=p->next){
        fprintf(ptr,"%s,%s,%d",p->kitapAdi,p->ISBN,p->adet) ;
        if(p->next != NULL){
            fprintf(ptr,"\n");
        }
    }
    fclose(ptr) ;
}

KITAP* kitapOlustur(){
    KITAP *temp = (KITAP*)malloc(sizeof(KITAP)) ;

    int k ;
    int cntrl = 1 ;

    if(temp == NULL){
        printf("Error ! ") ;
        exit(-1) ;
    }

    printf("\nKitap Adi : ") ;fflush(stdin) ; fgets(temp->kitapAdi,30,stdin) ; temp->kitapAdi[strlen(temp->kitapAdi) - 1] = '\0';
    
    while(cntrl){
        printf("\nISBN : ") ; scanf("%s",temp->ISBN) ;
        if(strlen(temp->ISBN) == 13){
            cntrl = 0 ;
        }
        else{
            printf("\nISBN 13 haneli olmalidir !") ;
        }
    }

    printf("\nAdet :") ; scanf("%d",&k) ; 
    temp->adet = k ;
    kitapOrnekOlustur(&temp,k) ;

    temp->next = NULL ;

    return temp ;
}

int kitapKontrol(KITAP* head , char ISBN[]){
    KITAP* p ;
    for(p=head; p != NULL ; p=p->next){
        if(strcmp(p->ISBN,ISBN) == 0){
            return 1 ;
        }
    }
    return 0 ;
}

void kitapEkle(KITAP **head , KITAP *yeniKitap){
    KITAP *p ;

    if(kitapKontrol(*head,yeniKitap->ISBN)){
        printf("\nAyni ISBN'ye sahip kitap bulunuyor !") ;
        return ;
    }

    if(*head == NULL){
        *head = yeniKitap ;
        return ;
    }
    
    for(p=*head ; p->next != NULL ; p=p->next) ;

    p->next = yeniKitap ;
}

void kitapSil(KITAP** head,KITAPYAZAR*** kitapYazarData , int* kitapyazarSayaci , KITAPODUNC*** kitapOduncData , int* kitapOduncSayaci){
    KITAP* p ;
    p = *head ;
    
    char ISBN[14] ;
    char kitapAdi[30] ;

    int control = 1 ;
    int i  , j ;

    KITAP* kitap ;

    int op = 0;
    kitap = kitapBul((*head),&op,1) ;
    if(kitap == NULL){
        printf("\nKitap Bulunamadi\n") ;
        return ;
    }
    strcpy(ISBN,kitap->ISBN) ;
    strcpy(kitapAdi,kitap->kitapAdi) ;

    if(strcmp(p->ISBN,kitap->ISBN) == 0){
        *head = p->next ;
        free(p) ;
        control = 0 ;
    }

   else{
        while(control && p->next!= NULL){
            if(strcmp(p->next->ISBN,kitap->ISBN) == 0){
                KITAP* temp = p->next ;
                p->next = p->next->next ;
                free(temp) ;
                control = 0 ;
            }
            else p = p->next ;
    }

   } 

    if(control) printf("\nKitap Bulunamadi\n") ;

    for(i=0 ; i<(*kitapyazarSayaci) ; i++){
        if(strcmp((*kitapYazarData)[i]->ISBN,ISBN) == 0){
            (*kitapyazarSayaci)-- ;
            (*kitapYazarData)[i] = (*kitapYazarData)[(*kitapyazarSayaci)] ;
            (*kitapYazarData) = (KITAPYAZAR**) realloc((*kitapYazarData),sizeof(KITAPYAZAR*)*(*kitapyazarSayaci)) ;
            i-- ;
        }
    }

    for(i=0;i<(*kitapOduncSayaci);i++){
        if(strcmp(ISBN,isbnBul((*kitapOduncData)[i]->EtiketNo)) == 0){
            for(j=i;j<(*kitapOduncSayaci)-1;j++){
                (*kitapOduncData)[j] = (*kitapOduncData)[j+1] ;
            }
            (*kitapOduncSayaci)-- ;
            (*kitapOduncData) = (KITAPODUNC**) realloc((*kitapOduncData),sizeof(KITAPODUNC*)*(*kitapOduncSayaci)) ;
        }
    }

    printf("\n %s:%s Kitabi Silindi \n",ISBN,kitapAdi) ;
}

void kitapGuncelle(KITAP* headKitap , KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci, KITAPYAZAR** kitapYazarData , int kitapYazarDataSayaci){
    KITAP* kitap ;
    char ISBN[14] , etiket[20];
    char eskiISBN[14] ;
    char kitapNu[10] ;

    int op = 0 ;
    int cntrl = 1 ;
    int i ;

    kitap = kitapBul(headKitap,&op,1) ;

    if(kitap == NULL){
        printf("\nKitap Bulunamadi\n") ;
        return ;
    }

    printf("\nKitabin Simdiki Adi : %s\nKitabin Simdiki ISBN'si : %s\n",kitap->kitapAdi,kitap->ISBN) ;
    strcpy(eskiISBN,kitap->ISBN) ;

    printf("Yeni Kitap Adi : ") ;fflush(stdin) ; fgets(kitap->kitapAdi,30,stdin) ; kitap->kitapAdi[strlen(kitap->kitapAdi) - 1] = '\0';
    while(cntrl){
        printf("Yeni ISBN : ") ; scanf("%s",ISBN) ;
        if(strlen(ISBN) != 13){
            printf("\nISBN 13 Haneli Olmalidir\n") ;
        }
        if(kitapKontrol(headKitap,ISBN) == 1){
            printf("\nBu ISBN'ye Sahip Bir Kitap Zaten Var\n") ;
        }
        else{
            strcpy(kitap->ISBN,ISBN) ;
            cntrl = 0 ;
        }
    }

    for(i=0;i<kitapYazarDataSayaci;i++){
        if(strcmp(kitapYazarData[i]->ISBN,eskiISBN) == 0){
            strcpy(kitapYazarData[i]->ISBN,kitap->ISBN) ;
        }
    }

    for(i=0;i<kitapOduncDataSayaci;i++){
        strcpy(etiket,kitapOduncData[i]->EtiketNo) ;
        sscanf(etiket,"%[^_]%s",ISBN,kitapNu) ;
        if(strcmp(ISBN,eskiISBN) == 0){
            sprintf(kitapOduncData[i]->EtiketNo,"%s%s",kitap->ISBN,kitapNu) ;
        }
    } 
} 

KITAP* kitapAra(KITAP* head ,char*c, int (*f)(KITAP* , char*)){
    KITAP* p ;
    for(p=head ; p != NULL ; p=p->next){
       if(f(p,c) == 1){
              return p ;
       }
    }
    return NULL ;
}

int kitapISBNAra(KITAP* p , char* ISBN){
    if(strcmp(p->ISBN,ISBN) == 0){
        return 1 ;
    }
    return 0 ;
}

int kitapAdiAra(KITAP* p , char* kitapAdi){
    if(strcmp(p->kitapAdi,kitapAdi) == 0){
        return 1 ;
    }
    return 0 ;
}

KITAP* kitapBul(KITAP* headKitap , int* op , int cntrl){
    char kitapISBN[30] , kitapAdi[30] ;

    KITAP* kitap ;
    while((*op) == 0 ){
        printf("\n Kitap ISBN ile islem yapmak icin 1 \n Kitap ismi ile islem yapmak icin 2 \n Secim :") ; scanf("%d",op) ;
        switch((*op)){
            case 1 :
                printf("\nKitap ISBN :") ; scanf("%s",kitapISBN) ;
                kitap = kitapAra(headKitap,kitapISBN,kitapISBNAra) ;
                break ;
            case 2 :
                printf("\nKitap Adi :"); fflush(stdin) ; fgets(kitapAdi,30,stdin) ; kitapAdi[strlen(kitapAdi) - 1] = '\0';
                kitap = kitapAra(headKitap,kitapAdi,kitapAdiAra) ;
                if(cntrl == 1 &&  kitap != NULL && kitapAra(kitap->next,kitapAdi,kitapAdiAra) != NULL) {
                    printf("\nAyni isimde birden fazla kitap bulundu. Lutfen ISBN ile arama yapiniz.\n");
                    (*op) = 0 ;
                }
                break ;
            default :
                printf("\nHatali Secim\n") ;
                (*op) = 0 ;
                break ;
            }
    }
    return kitap ;  
}

char* isbnBul(char* etiketNo){
    char* ISBN ;
    char temp[20] ;

    strcpy(temp,etiketNo) ;
    ISBN = (char*)malloc(14*sizeof(char)) ;
    strcpy(ISBN,strtok(temp,"_")) ;
    ISBN[strlen(ISBN)] = '\0' ;
    return ISBN ;
}

void kitapGoruntule(YAZAR* headYazar , KITAP* headKitap,KITAPYAZAR** kitapYazarData , int kitapYazarSayaci){    
    KITAP* p ;
    char c[30] ;
    int op = 0 ;
    
    p = kitapBul(headKitap,&op,0) ;
    if(p == NULL){
        printf("\nKitap Bulunamadi\n") ;
        return ;
    }

    strcpy(c,p->kitapAdi) ;
    while(p != NULL){
        printf("\n--------------------------------------------\n") ;
        kitapOrnekYazdir(p) ;
        kitapYazariYaz(headYazar,kitapYazarData,kitapYazarSayaci,p->ISBN) ;
        if(op == 2) p = kitapAra(p->next,c,kitapAdiAra) ;
        else p = NULL ;
    }
}

void kitapRaftakileriListele(KITAP* headKitap){
    KITAP* tempKitap ;
    KITAPORNEK* tempOrnek ;

    int cntrl = 0 ;
    char oncekiISBN[14] = "" ;

    for(tempKitap = headKitap ; tempKitap != NULL ; tempKitap = tempKitap->next){
        tempOrnek = tempKitap->head ;
        while(tempOrnek != NULL){
            if(strcmp(tempOrnek->Durum,"RAFTA") == 0){
                if(++cntrl == 1)printf("\nRafta Bulunan Kitaplar\n") ;
                if(strcmp(tempKitap->ISBN,oncekiISBN) != 0){
                    printf("\nKitap Adi : %s\n",tempKitap->kitapAdi) ;
                }
                printf("Kitap Etiketi : %s\n",tempOrnek->EtiketNo) ;
                strcpy(oncekiISBN,tempKitap->ISBN);
            }
            tempOrnek = tempOrnek->next ;
        } 
    }
    if(cntrl == 0)printf("\nRafta Kitap Bulunmamaktadir.\n") ;
}

void kitapOrnekOlustur(KITAP **kitap , int k){
    KITAPORNEK *sonOrnek ;

    int i ;
    char num[5] ;
    char etiket[20] ;
    char durum[9] = "RAFTA" ;

    for(i=1;i<=k;i++){
        KITAPORNEK *p ;
        p = (KITAPORNEK*) malloc(sizeof(KITAPORNEK)) ;

        if(p == NULL){
            printf("Error ! ") ;
            exit(-1) ;
        }
        
        sprintf(num,"%d",i) ;
        strcpy(etiket,(*kitap)->ISBN) ;
        strcat(etiket,"_") ;
        strcat(etiket,num) ;
        strcpy(p->EtiketNo,etiket) ;
        strcpy(p->Durum,durum) ;

        if(i == 1){
            (*kitap)->head = p ;
            sonOrnek = p ;
        }
        else{
            sonOrnek->next = p ;
            sonOrnek = p ;
        }
    }   
}

void kitapOrnekYazdir(KITAP* temp){
    KITAPORNEK *p ;
    
    printf("\n\nKitap Adi : %s\nKitap ISBN : %s\nKitap Adet : %d \n",temp->kitapAdi,temp->ISBN,temp->adet) ;
    for(p=temp->head ; p != NULL ; p=p->next){
        printf("\nEtiket No :%s   Durum : %s",p->EtiketNo,p->Durum) ;
    }
}

void yazarVeriAl(YAZAR** head , int *yazarSayaci){
    FILE* ptr ;
    int id ;

    YAZAR* temp ;

    ptr = fopen("Yazarlar.csv","r") ;
    if(ptr == NULL){
        printf("Error ! ") ;
        exit(-1);
    }
    
    while(!feof(ptr)){
        YAZAR* p ;
        p = (YAZAR*) malloc(sizeof(YAZAR)) ; 
        if(p == NULL){
            printf("Error ! ") ;
            exit(-1) ;
        }

        fscanf(ptr,"%d,%[^,],%[^\n] ",&id,p->yazarAd,p->yazarSoyad);
        p->yazarID = id ;
        p->next = NULL ;
        (*yazarSayaci)++ ;
        yazarEkle(head,p) ;     
    }
    fclose(ptr) ;
   for(temp=*head ; temp->next != NULL ; temp=temp->next) temp->yazarSoyad[strlen(temp->yazarSoyad)] = '\0' ;     
} 

void yazarVeriYaz(YAZAR* head){
    YAZAR* p ;
    FILE* ptr ;
    ptr = fopen("Yazarlar.csv","w+") ;
    for(p=head; p != NULL ; p=p->next){
        fprintf(ptr,"%d,%s,%s",p->yazarID,p->yazarAd,p->yazarSoyad) ;

        if(p->next != NULL){
            fprintf(ptr,"\n");
        }
    }
    fclose(ptr) ;
}

YAZAR* yazarOlustur(int *yazarSayaci){
    YAZAR* temp = (YAZAR*)malloc(sizeof(YAZAR)) ;
    if(temp == NULL){
        printf("Error ! ") ;
        exit(-1) ;
    }
    (*yazarSayaci)++;

    temp->yazarID = *yazarSayaci ;
    printf("\nYazar Ad : ") ; scanf("%s",temp->yazarAd) ;
    printf("\nYazar Soyad : ") ; scanf("%s",temp->yazarSoyad) ;

    temp->next = NULL ;

    return temp ;
}

void yazarEkle(YAZAR** head , YAZAR* yazar){
    YAZAR* p ;
    if(*head == NULL){
        *head = yazar ;
        return ;
    }
    
    for(p=*head ; p->next != NULL ; p=p->next) ;
    
    p->next = yazar ; 
}

void yazarGuncelle(YAZAR* headYazar){
    YAZAR* yazar ;

    int op = 0 ;
    yazar = yazarBul(headYazar,&op,1) ;

    if(yazar == NULL){
        printf("\nYazar Bulunamadi\n") ;
        return ;
    }

    printf("\nYazarin Simdiki Adi : %s\nYazarin Simdiki Soyadi : %s\nYazarin Simdiki ID'si : %d\n",yazar->yazarAd,yazar->yazarSoyad,yazar->yazarID) ;
    printf("Yeni Ad : ") ; scanf("%s",yazar->yazarAd) ;
    printf("Yeni Soyad : ") ; scanf("%s",yazar->yazarSoyad) ;
}

YAZAR* yazarIdAra(YAZAR* head , int yazarID){
    YAZAR* p ;
    for(p=head ; p != NULL ; p=p->next){
        if(p->yazarID == yazarID){
            return p ;
        }
    }
    return NULL ;
}

YAZAR* yazarAdSoyadAra(YAZAR* p , char* yazarAd , char* yazarSoyad ){
    YAZAR* temp ;
    
    for(temp=p ; temp != NULL ; temp=temp->next){
        if(strcmp(temp->yazarAd,yazarAd) == 0 && strcmp(temp->yazarSoyad,yazarSoyad) == 0){
            return temp ;
        }
    }
    return NULL ;
}

YAZAR* yazarAdVeyaSoyadAra(YAZAR* headYazar , char* c ,int  (*f)(YAZAR* , char*)){
    YAZAR* p ;
    for(p=headYazar; p != NULL ; p=p->next){
        if(f(p,c)){
            return p ;
        }
    }
    return NULL ;
}

int yazarAdKontrol(YAZAR* p  , char* c ){
    if(strcmp(p->yazarAd,c) == 0){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

int yazarSoyadKontrol(YAZAR* p , char* c ){
    if(strcmp(p->yazarSoyad,c) == 0){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

YAZAR* yazarBul(YAZAR* headYazar, int* op , int cntrl){
    YAZAR* yazar ;
    int yazarID ;
    char ad[30] , soyad[30] ;
    while((*op) == 0){
        printf("\n Yazar ID ile islem yapmak icin 1 \n Ad-Soyad ile islem yapmak icin 2 \n Sadece ad ile islem yapmak icin 3 \n Sadece soyadi ile islem yapmak icin 4 \n Secim :") ; scanf("%d",op) ;
        switch((*op)){
            case 1 :
                printf("\nYazar ID :") ; scanf("%d",&yazarID) ;
                yazar = yazarIdAra(headYazar,yazarID) ;
                break ;
            case 2 :
                printf("\nYazar Ad :") ; scanf("%s",ad) ; printf("\nYazar Soyad :") ; scanf("%s",soyad) ;
                yazar = yazarAdSoyadAra(headYazar,ad,soyad) ;
                if(cntrl == 1 && yazar != NULL && yazarAdSoyadAra(yazar->next,ad,soyad) != NULL){
                    printf("\nAyni isim soyisimde birden fazla yazar var! Lutfen farkli bir turde arama yapiniz.\n") ;
                    (*op) = 0 ;
                }
                break ;
            case 3 :
                printf("\nYazar Ad :") ; scanf("%s",ad) ;
                yazar = yazarAdVeyaSoyadAra(headYazar,ad,yazarAdKontrol) ;
                if(cntrl == 1 && yazar != NULL && yazarAdVeyaSoyadAra(yazar->next,ad,yazarAdKontrol) != NULL){
                    printf("\nAyni isimde birden fazla yazar var! Lutfen farkli bir turde arama yapiniz.\n") ;
                    (*op) = 0 ;
                }
                break ;
            case 4 :
                printf("\nYazar Soyad :") ; scanf("%s",soyad) ;
                yazar = yazarAdVeyaSoyadAra(headYazar,soyad,yazarSoyadKontrol) ;
                if(cntrl == 1 && yazar != NULL && yazarAdVeyaSoyadAra(yazar->next,soyad,yazarSoyadKontrol) != NULL){
                    printf("\nAyni soyismide birden fazla yazar var! Lutfen farkli bir turde arama yapiniz.\n") ;
                    (*op) = 0 ;
                }
                break ;
            default :
                printf("\nHatali Secim\n") ;
                op = 0 ;
                break ;
        }
    }
    return yazar ;
}

void yazarSil(YAZAR** head, KITAPYAZAR** kitapYazarData , int kitapYazarSayaci){
    YAZAR* p ;
    YAZAR* tempYazar ;

    int yazarID ;
    char ad[30] , soyad[30] ;

    int op = 0 ;
    int i ;

    if((*head) == NULL){
        printf("\nListe Bos\n") ;
        return ;
    }
       
    p = yazarBul((*head),&op,0) ;
    if(p == NULL){
        printf("\nYazar Bulunamadi\n") ;
        return ;
    }

    strcpy(ad,p->yazarAd) ; strcpy(soyad,p->yazarSoyad) ;
    while(p!= NULL){
        printf("\n%d ID'sine sahip %s %s isimli Yazar Siliniyor\n",p->yazarID,p->yazarAd,p->yazarSoyad) ;
        yazarID = p->yazarID ;
        if(p == (*head)){
        (*head) = (*head)->next ;
        free(p) ;
        }

        else {
            for(tempYazar=(*head) ; tempYazar->next != p ; tempYazar=tempYazar->next) ;

            tempYazar->next = p->next ;
            free(p) ;
        }

        
        for(i=0 ; i<kitapYazarSayaci ; i++){
            if(kitapYazarData[i]->yazarID == yazarID){
                kitapYazarData[i]->yazarID = -1 ;
            }
        }

        if(op == 2) p = yazarAdSoyadAra((*head),ad,soyad) ;
        else if(op == 3) p = yazarAdVeyaSoyadAra((*head),ad,yazarAdKontrol);
        else if(op == 4)  p = yazarAdVeyaSoyadAra((*head),soyad,yazarSoyadKontrol);
        else p = NULL ;
    } 
}

void yazarGoruntule(YAZAR* headYazar, KITAPYAZAR** kitapYazarData , int kitapYazarSayaci, KITAP* headKitap){
    int yazarID ;
    char ad[30] , soyad[30] ;

    YAZAR* yazar ;
    KITAP* kitap ;

    int op = 0 ;
    int cntrl = 0 ;
    int i ;

    yazar = yazarBul(headYazar,&op,0) ;
    if(yazar == NULL){
        printf("\nYazar Bulunamadi\n") ;
        return ;
    } 

    strcpy(ad,yazar->yazarAd) ; strcpy(soyad,yazar->yazarSoyad) ;
    while(yazar != NULL){
        printf("\n--------------------------------------------\n") ;
        printf("\nYazar ID : %d\nYazar Ad : %s\nYazar Soyad : %s\n",yazar->yazarID,yazar->yazarAd,yazar->yazarSoyad) ;

        yazarID = yazar->yazarID ;
        cntrl = 0 ;
        for(i=0 ; i<kitapYazarSayaci ; i++){
            if(kitapYazarData[i]->yazarID == yazarID){
                
                kitap = kitapAra(headKitap,kitapYazarData[i]->ISBN,kitapISBNAra) ;
                if(kitap != NULL){
                    if(++cntrl == 1) printf("\n-----Yazarin Yazdigi Kitaplar-----") ;
                //  printf("\nKitap Adi : %s\nKitap ISBN : %s\nKitap Adet : %d\n",kitap->kitapAdi,kitap->ISBN,kitap->adet) ;
                    kitapOrnekYazdir(kitap) ;
                    kitapYazariYaz(headYazar,kitapYazarData,kitapYazarSayaci,kitapYazarData[i]->ISBN) ;
                }
                }
        }

        if(cntrl == 0) printf("\nYazarin Yazdigi Kitap Bulunmamaktadir\n") ;

        if(op == 2) yazar = yazarAdSoyadAra(yazar->next,ad,soyad) ;
        else if(op == 3) yazar = yazarAdVeyaSoyadAra(yazar->next,ad,yazarAdKontrol);
        else if(op == 4)  yazar = yazarAdVeyaSoyadAra(yazar->next,soyad,yazarSoyadKontrol);
        else yazar = NULL ;
    }
}

void kitapYazarAlanAyir(KITAPYAZAR*** kitapYazarData , int* kitapYazarSayaci){
    if((*kitapYazarData) == NULL){
            (*kitapYazarData) = (KITAPYAZAR**)malloc(sizeof(KITAPYAZAR*)) ;
        }

    else{
        (*kitapYazarData) = (KITAPYAZAR**)realloc((*kitapYazarData),sizeof(KITAPYAZAR*)*((*kitapYazarSayaci)+1)) ;
        }
    (*kitapYazarData)[(*kitapYazarSayaci)] = (KITAPYAZAR*)malloc(sizeof(KITAPYAZAR)) ;
}

void kitapYazarVeriAl(KITAPYAZAR*** kitapYazarData , int* kitapYazarSayaci){
    FILE* ptr;
    ptr = fopen("KitapYazar.csv","r") ;

    int yazarID ;

    if(ptr == NULL){
        printf("Error! ") ;
        exit(-1);
    }

    while(!feof(ptr)){
        kitapYazarAlanAyir(kitapYazarData,kitapYazarSayaci) ;

        fscanf(ptr,"%[^,],%d ",(*kitapYazarData)[(*kitapYazarSayaci)]->ISBN,&yazarID) ;
        (*kitapYazarData)[(*kitapYazarSayaci)]->yazarID = yazarID ;
        (*kitapYazarSayaci)++;
    }
    fclose(ptr) ;
}

void kitapYazarVeriYaz(KITAPYAZAR** kitapYazarData , int kitapYazarSayaci){
    int i ;
    FILE* ptr ;
    ptr = fopen("KitapYazar.csv","w+") ;
    if(ptr == NULL){
        printf("Error! ") ;
        exit(-1);
    }
    for(i=0 ; i<kitapYazarSayaci ; i++){
        fprintf(ptr,"%s,%d",kitapYazarData[i]->ISBN,kitapYazarData[i]->yazarID) ;
        if(i+1<kitapYazarSayaci){
            fprintf(ptr,"\n");
        }
    }
    fclose(ptr) ;
}

void kitapYazarEslestir(KITAPYAZAR*** kitapYazarData , int *kitapYazarSayaci , KITAP* headKitap, YAZAR* headYazar){
    char kitapISBN[30]  , kitapAdi[30];
    
    int yazarID ;
    char ad[30] , soyad[30] ;

    int op = 0 ;
    int i ;
    KITAP* kitap ;
    YAZAR* yazar ;

    kitap = kitapBul(headKitap,&op,1) ;
    if(kitap == NULL){
        printf("\nKitap Bulunamadi\n") ;
        return ;
    }

    op = 0 ;
    yazar = yazarBul(headYazar,&op,1) ;

    if(yazar == NULL){
        printf("\nYazar Bulunamadi\n") ;
        return ;
    }

    strcpy(kitapISBN,kitap->ISBN) ; strcpy(kitapAdi,kitap->kitapAdi) ; 
    yazarID = yazar->yazarID ; strcpy(ad,yazar->yazarAd) ; strcpy(soyad,yazar->yazarSoyad) ;
    for(i=0 ; i<(*kitapYazarSayaci) ; i++){
        if(strcmp((*kitapYazarData)[i]->ISBN,kitapISBN) == 0 && (*kitapYazarData)[i]->yazarID == yazarID){
            printf("\nKitap ve Yazar Zaten Eslestirilmis\n") ;
            return ;
        }
    }

    kitapYazarAlanAyir(kitapYazarData,kitapYazarSayaci) ;
    strcpy((*kitapYazarData)[(*kitapYazarSayaci)]->ISBN,kitapISBN) ;
    (*kitapYazarData)[(*kitapYazarSayaci)]->yazarID = yazarID ;
    (*kitapYazarSayaci)++ ;

    printf("\nKitap ve Yazar Eslestirildi\n") ;
}

void kitapYazariYaz(YAZAR* headYazar,KITAPYAZAR** kitapYazarData , int kitapYazarSayaci , char* ISBN){
    int i ;
    int cntrl = 0 ;
    YAZAR* yazar ;
    printf("\nKitap Yazar(lar)i  :") ;
    for(i=0 ; i<kitapYazarSayaci ; i++){
        if(strcmp(kitapYazarData[i]->ISBN,ISBN) == 0){
            cntrl++;
            yazar = yazarIdAra(headYazar,kitapYazarData[i]->yazarID) ;

            if(yazar != NULL) printf(" \n\tID : %d , Ad-Soyad : %s %s",yazar->yazarID,yazar->yazarAd,yazar->yazarSoyad) ;
        }
    }
    if(cntrl == 0){
        printf("  Bulunamadi ! ") ;
    }
}

void kitapYazariGuncelle(KITAP* headKitap , YAZAR* headYazar , KITAPYAZAR** kitapYazarData , int kitapYazarDataSayaci){
    KITAP* kitap ;
    YAZAR* yazar ;
    YAZAR* yeniYazar ;
    
    char yazarAd[30] , yazarSoyad[30] ;

    int i ,j  ;
    int op = 0 , op2;
    int cnt = 0;
    int cntrl ;
    int idKontrol = 0 ;

    kitap = kitapBul(headKitap,&op,1) ;

    if(kitap == NULL){
        printf("\nKitap Bulunamadi\n") ;
        return ;
    }

    for(i=0;i<kitapYazarDataSayaci;i++){
        if(strcmp(kitapYazarData[i]->ISBN,kitap->ISBN) == 0){
            cnt++;
            op = 0 ;
            if(kitapYazarData[i]->yazarID != -1){
                yazar = yazarIdAra(headYazar,kitapYazarData[i]->yazarID) ;
                strcpy(yazarAd,yazar->yazarAd) ; strcpy(yazarSoyad,yazar->yazarSoyad) ;
                yazarAd[strlen(yazarAd)-1] = '\0' ; yazarSoyad[strlen(yazarSoyad)-1] = '\0' ;
                idKontrol = 1 ;
            }
            else cnt-- ;
            
            op = 0 ;
            while(op == 0){
                if(idKontrol){
                    printf("\n%s %s isimli yazarin kitap eslestirmesini bitirmek icin 1 ,\ndegistirmek icin 2 ,\nislem yapmadan devam etmek icin 3 giriniz : ",yazarAd,yazarSoyad) ; scanf(" %d",&op) ;
                    switch(op){
                    case 1:
                        kitapYazarData[i]->yazarID = -1 ;
                        break;

                    case 2:
                        op2 = 0 ;
                        yeniYazar = yazarBul(headYazar,&op2,1) ;

                        j=0; cntrl = 1 ;
                        if(yeniYazar == NULL){
                            printf("\nYazar Bulunamadi. Tekrar deneyiniz. \n") ;
                            op = 0 ;
                            cntrl = 0 ;
                        }          
                        while(cntrl && j<kitapYazarDataSayaci){
                            if(strcmp(kitapYazarData[j]->ISBN,kitap->ISBN) == 0){
                                if(kitapYazarData[j]->yazarID == yeniYazar->yazarID){
                                    printf("\nBu Kitabi Zaten Bu Yazar Yazmistir\n") ;
                                    cntrl = 0 ;
                                    op = 0 ;
                                }
                            }
                            j++;
                        }
                        if(cntrl) kitapYazarData[i]->yazarID = yeniYazar->yazarID ;
                        break;
                    case 3:
                        op = 1 ;
                        break ;
                    default:
                        printf("\nHatali Secim\n") ;
                        op = 0 ;
                        break;
                    }
                }
                else op = 1 ;                  
            }
        }
            
    }
    if(cnt == 0){
        printf("\nBu Kitaba Ait Yazar Bulunamadi\n") ;
        return ;
    }

}

void kitapOduncAlanAyir(KITAPODUNC*** kitapOduncData , int* kitapOduncDataSayaci){
    if((*kitapOduncData) == NULL){
        (*kitapOduncData) = (KITAPODUNC**)malloc(sizeof(KITAPODUNC*)) ;
    }

    else{
        (*kitapOduncData) = (KITAPODUNC**)realloc((*kitapOduncData),sizeof(KITAPODUNC*)*((*kitapOduncDataSayaci)+1)) ;
    }

    (*kitapOduncData)[(*kitapOduncDataSayaci)] = (KITAPODUNC*)malloc(sizeof(KITAPODUNC)) ;

}

void kitapOduncVeriAl(KITAPODUNC*** kitapOduncData ,KITAP* headKitap , OGRENCI* headOgrenci ,int* kitapOduncDataSayaci){
    FILE* ptr;
  
    // etiket no,  ogrenci no, islem(0:alma , 1:verme) , tarih 
    ptr = fopen("KitapOdunc.csv","r") ;

    int islem ;
    int gun , ay , yil ;
    char kitapISBN[15] ;
    char kitapNu[7] ;

    int cntrl ;

    KITAP* kitap ;
    KITAPORNEK* temp ;

    //OGRENCI* ogrenci ;

    if(ptr == NULL){
        printf("Error! ") ;
        exit(-1);
    }

    while(!feof(ptr)){
        
        kitapOduncAlanAyir(kitapOduncData,kitapOduncDataSayaci) ;

        fscanf(ptr,"%[^_]_%[^,],%[^,],%d,%d.%d.%d ",kitapISBN,kitapNu,(*kitapOduncData)[(*kitapOduncDataSayaci)]->ogrID,&islem,&gun,&ay,&yil) ;
       
        sprintf((*kitapOduncData)[(*kitapOduncDataSayaci)]->EtiketNo,"%s_%s",kitapISBN,kitapNu) ;

        (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTipi = islem ;
        (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.gun = gun ;
        (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.ay = ay ;
        (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.yil = yil ;
       
        kitap = kitapAra(headKitap,kitapISBN,kitapISBNAra) ;
        temp = kitap->head ;
        cntrl = 1 ;

        if(islem){              //geri ver
            while(cntrl){
                if(strcmp(temp->EtiketNo,(*kitapOduncData)[(*kitapOduncDataSayaci)]->EtiketNo) == 0){
                    strcpy(temp->Durum,"RAFTA");
                    cntrl = 0 ;
                }
                else{
                    temp = temp->next ;
                }
            }

         /*   ogrenci = ogrenciIdAra(headOgrenci,(*kitapOduncData)[(*kitapOduncDataSayaci)]->ogrID) ;

            if(kitapTarihKontrolu((*kitapOduncData),(*kitapOduncDataSayaci))){
                ogrenci->puan -=10 ;
            } */

        }

        else{                   // al 
            while(cntrl){
               if(strcmp(temp->EtiketNo,(*kitapOduncData)[(*kitapOduncDataSayaci)]->EtiketNo) == 0){
                    strcpy(temp->Durum,(*kitapOduncData)[(*kitapOduncDataSayaci)]->ogrID);
                    cntrl = 0 ;
                }
                else{
                    temp = temp->next ;
                }
            }
        }  

        (*kitapOduncDataSayaci)++;

    }
    
    fclose(ptr) ;
}

void kitapOduncVeriYaz(KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci){
    FILE* ptr;
    ptr = fopen("KitapOdunc.csv","w+") ;

    int i ;

    if(ptr == NULL){
        printf("Error! ") ;
        exit(-1);
    }

    for(i=0 ; i<kitapOduncDataSayaci ; i++){
        fprintf(ptr,"%s,%s,%d,%d.%d.%d",kitapOduncData[i]->EtiketNo,kitapOduncData[i]->ogrID,kitapOduncData[i]->islemTipi,kitapOduncData[i]->islemTarihi.gun,kitapOduncData[i]->islemTarihi.ay,kitapOduncData[i]->islemTarihi.yil) ;
        if(i+1<kitapOduncDataSayaci){
            fprintf(ptr,"\n");
        }
    }
    fclose(ptr) ;
}

void kitapOduncIslemi(OGRENCI* headOgrenci,KITAP* headKitap , KITAPODUNC*** kitapOduncData , int *kitapOduncDataSayaci,int (*f)(OGRENCI* ,KITAP* , KITAPODUNC*** , int* , int ,int ,int)){
    int gun , ay , yil ;
    int op = 0 ;

    KITAP* kitap ;
    OGRENCI* ogrenci ; 

    ogrenci = ogrenciBul(headOgrenci,&op,1) ;

    if(ogrenci == NULL){
        printf("\nOgrenci Bulunamadi\n") ;
        return ;
    }

    op = 0 ;
    kitap = kitapBul(headKitap,&op,1) ;

    if(kitap == NULL){
        printf("\nKitap Bulunamadi\n") ;
        return ;
    }

    printf("\nIslem Tarihi (Gun.Ay.Yil) : ") ;
    scanf("%d.%d.%d",&gun,&ay,&yil) ;

    if(f(ogrenci,kitap,kitapOduncData,kitapOduncDataSayaci,gun,ay,yil)){
        return ;
    }

    printf("\nIslem Basarili\n") ;
}

int kitapOduncAlma(OGRENCI* ogrenci,KITAP* kitap , KITAPODUNC*** kitapOduncData , int* kitapOduncDataSayaci, int gun ,int ay , int yil){
    KITAPORNEK* temp ;
    int cntrl = 1 ;

    if(ogrenci->puan < 0 ){
        printf("\nOgrenci Puani :%d . Kitap odunc alma islemi yapilamiyor \n",ogrenci->puan) ;
        return 1 ;
    }

    temp = kitap->head ;
    while(cntrl && temp != NULL){
        if(strcmp(temp->Durum,"RAFTA") == 0){
            strcpy(temp->Durum,ogrenci->ogrId) ;
            cntrl = 0 ;
        }
        else{
            temp = temp->next ;
        }
    }
    
   if(cntrl){
        printf("\nKitaplarin hepsi odunc alinmis\n") ;
        return 1 ;
    }

   kitapOduncAlanAyir(kitapOduncData,kitapOduncDataSayaci) ;
    
    strcpy((*kitapOduncData)[(*kitapOduncDataSayaci)]->EtiketNo,temp->EtiketNo) ;
    strcpy((*kitapOduncData)[(*kitapOduncDataSayaci)]->ogrID,ogrenci->ogrId) ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTipi = 0 ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.gun = gun ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.ay = ay ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.yil = yil ;

    (*kitapOduncDataSayaci)++ ;
    
    return 0 ;
}

int kitapTeslimEtme(OGRENCI* ogrenci,KITAP* kitap , KITAPODUNC*** kitapOduncData , int *kitapOduncDataSayaci,int gun ,int ay , int yil){
    int cntrl = 1 ;
    
    KITAPORNEK* temp ;

    temp = kitap->head ;
    while(cntrl && temp != NULL){
        if(strcmp(temp->Durum,ogrenci->ogrId) == 0){
            strcpy(temp->Durum,"RAFTA") ;
            cntrl = 0 ;
        }
        else{
            temp = temp->next ;
        }
    }

    if(cntrl){
        printf("\nOgrenci bu kitaba sahip degil\n") ;
        return 1 ;
    }

    kitapOduncAlanAyir(kitapOduncData,kitapOduncDataSayaci) ;

    strcpy((*kitapOduncData)[(*kitapOduncDataSayaci)]->EtiketNo,temp->EtiketNo) ;
    strcpy((*kitapOduncData)[(*kitapOduncDataSayaci)]->ogrID,ogrenci->ogrId) ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTipi = 1 ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.gun = gun ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.ay = ay ;
    (*kitapOduncData)[(*kitapOduncDataSayaci)]->islemTarihi.yil = yil ;


    if(kitapTarihKontrolu((*kitapOduncData),(*kitapOduncDataSayaci))){
        printf("\nOgrenciye gecikme cezasi uygulandi\n") ;
        ogrenci->puan -= 10 ;
    }

    (*kitapOduncDataSayaci)++ ; 

    return 0 ;
}

int kitapTarihKontrolu(KITAPODUNC** kitapoduncdata , int i  ){ // 0 : zamaninda / daha teslim edilmemis , 1: gecikme
    int j ;
    int fark ;
    for(j=i;j>=0;j--){
        if(strcmp(kitapoduncdata[i]->ogrID,kitapoduncdata[j]->ogrID) == 0 && strcmp(kitapoduncdata[i]->EtiketNo,kitapoduncdata[j]->EtiketNo) == 0 && kitapoduncdata[j]->islemTipi == 0){
            fark = (kitapoduncdata[i]->islemTarihi.yil - kitapoduncdata[j]->islemTarihi.yil)*365 + (kitapoduncdata[i]->islemTarihi.ay - kitapoduncdata[j]->islemTarihi.ay)*30 + (kitapoduncdata[i]->islemTarihi.gun - kitapoduncdata[j]->islemTarihi.gun) ;
            if(fark > 15){
                return 1 ;
            }
            else{
                return 0 ;
            }
        }
    }

    return 0 ;
}

void kitapOduncZamaniGecmisler(KITAPODUNC** kitapOduncData,KITAP* headKitap ,int kitapOduncDataSayaci){
    int i ;
    int ktp = 0 ;

    char ISBN[14] ;
    KITAP* kitap ;

    for(i=kitapOduncDataSayaci-1;i>=0;i--){
        if(kitapOduncData[i]->islemTipi == 1 && kitapTarihKontrolu(kitapOduncData,i)){

            strcpy(ISBN,isbnBul(kitapOduncData[i]->EtiketNo)) ;
            kitap = kitapAra(headKitap,ISBN,kitapISBNAra) ;

            printf("\nZamaninda teslim edilmemis kitap adi : %s\n",kitap->kitapAdi) ;
            printf("Zamaninda teslim edilmemis kitap etiket numarasi : %s\n",kitapOduncData[i]->EtiketNo) ;

            ktp++;
        }
    }

    if(ktp == 0) printf("\nZamaninda teslim edilmemis kitap bulunmamaktadir. \n") ;
}


void butunOduncGoruntule(KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci){
    int i ;
    for(i = 0 ; i < kitapOduncDataSayaci ; i++){
        printf("\nEtiket No : %s\n",kitapOduncData[i]->EtiketNo) ;
        printf("Ogrenci ID : %s\n",kitapOduncData[i]->ogrID) ;
        printf("Islem Tipi : %d\n",kitapOduncData[i]->islemTipi) ;
        printf("Islem Tarihi : %d.%d.%d\n",kitapOduncData[i]->islemTarihi.gun,kitapOduncData[i]->islemTarihi.ay,kitapOduncData[i]->islemTarihi.yil) ;
    }
}

void butunKitapGoruntule(KITAP* head ){
    
    KITAP* p ;
    for(p=head; p != NULL ; p=p->next){
        printf("\n%s %s",p->kitapAdi,p->ISBN) ;
    }
}

void butunYazarGoruntule(YAZAR* head ){
    
    YAZAR* p ;
    for(p=head; p != NULL ; p=p->next){
        printf("\n%d)%s %s",p->yazarID,p->yazarAd,p->yazarSoyad) ;
    }

}

void butunKitapYazarGoruntule(KITAPYAZAR** kitapYazarData , int kitapYazarDataSayaci){
    int i ;
    for(i=0 ; i<kitapYazarDataSayaci ; i++){
        printf("\n%s -> %d",kitapYazarData[i]->ISBN,kitapYazarData[i]->yazarID) ;
    }
}

void bekle(int n){
    int i ;
    for ( i = 0; i < n; i++)
    {
        printf("...%d",i) ;
        fflush(stdout) ;
        sleep(1) ;
    }
}

void menuyeDon(){
    printf("\n\nMenuye donmek icin bir karakter giriniz...") ;
    fflush(stdin) ;
    getchar() ;
    clearAll() ;
    
}

void ogrenciBellekTemizle(OGRENCI* head){
    OGRENCI *temp = head ;
    while(head != NULL){
        temp = head ;
        head = head->next ;
        free(temp) ;
    }
}

void kitapBellekTemizle(KITAP* head){
    KITAP *temp = head ;
    while(head != NULL){
        temp = head ;
        head = head->next ;
        free(temp) ;
    }
}

void yazarBellekTemizle(YAZAR* head){
    YAZAR *temp = head ;
    while(head != NULL){
        temp = head ;
        head = head->next ;
        free(temp) ;
    }
}

void kitapYazarBellekTemizle(KITAPYAZAR** kitapYazarData , int kitapYazarDataSayaci){
    int i ;
    for(i=0 ; i<kitapYazarDataSayaci ; i++){
        free(kitapYazarData[i]) ;

    }
    free(kitapYazarData) ;
}

void kitapOduncBellekTemizle(KITAPODUNC** kitapOduncData , int kitapOduncDataSayaci){
    int i ;
    for(i=0 ; i<kitapOduncDataSayaci ; i++){
        free(kitapOduncData[i]) ;
    }
    free(kitapOduncData) ;
}