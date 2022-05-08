#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// KELOMPOK 1
// ANGGOTA :
// TESSALONICA PUTTRY    (672020167)
// USMAN SYACH           (672020201)
// VICTOR ANGKY METEKOHY (672020216)

// struct dan variabel global
struct data{
    int id;
    int pil;
    char *pembeli;
    char *barang;
    int jumlah;
    int harga;
    struct data *next;}*head, *tail, *current;
    void out();
    void Posisi();
int history=1;
char hist[100][100];

void Posisi(int x, int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD); // untuk menentukan posisi
}

// menu utama data
int main(){
    {
            system("COLOR E");
            char username[10];
            char password[10];
            int akses_login = 0;
            int i;

            printf("___________________________________________________________________________________________________\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
    printf("|                                  SELAMAT DATANG DI TOKO ELEKTRONIK                              |\n");
    printf("|                               SILAHKAN MASUKAN USERNAME DAN PASSWORD                            |\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                 |\n");
    printf("|                                                                                                 |\n");
    printf("                                    USERNAME :  ");
    scanf("%s",&username);
    printf("                                    PASSWORD :  ");
    for(akses_login=0;akses_login<9;akses_login++)
            { password[akses_login]=getch();
            printf("*"); }
            password[akses_login]='\0';
            if(strcmp(username,"admin")==0){
            if(strcmp(password,"672020167")==0){
    printf("\n");
    printf("|                                                                                                 |\n");
    printf("|                                                                                                 |\n");
    printf("|------------------------------------  lOGIN BERHASIL  -------------------------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
    printf("|---------------------------  KELOMPOK 1 (SISTEM INFORMASI TOKO)  --------------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
            Posisi(1, 15);
            for(i=0; i<97;i++){ //untuk buat loading sebanyak 30 bar
            printf("%c",254); //untuk buat bar loading 233 untuk lingkaran, 254 persegi
            Sleep(40); //untuk delaynya
            }
            }else{
    printf("\n|--------------------------  Maaf, password yang Anda masukkan salah  ----------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
            return 0;
            }
            }else{
    printf("\n|--------------------------  Maaf, username yang Anda masukkan salah  ----------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
            return 0;
            }
            system("pause >nul | echo \t\t\t\t                              Tekan tombol apapun untuk melanjutkan...");
            system("cls");
            }




    int menu,id,jumlah,harga,pil;
    char i,pembeli[50],barang[50];
    do{
    system("COLOR E"); //kuning
    printf("___________________________________________________________________________________________________\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
    printf("|                                  SELAMAT DATANG DI TOKO ELEKTRONIK                              |\n");
    printf("|-------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                 |\n");
    printf("|                                    1. Create Data                                               |\n");
    printf("|                                    2. Read Data                                                 |\n");
    printf("|                                    3. Sorting Data                                              |\n");
    printf("|                                    4. Searching Data                                            |\n");
    printf("|                                    5. Delete Data                                               |\n");
    printf("|                                    6. Update Data                                               |\n");
    printf("|                                    7. History Data                                              |\n");
    printf("|                                    8. Cetak File Data                                           |\n");
    printf("|                                    9. Exit                                                      |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
    printf("Pilih Menu: ");
    scanf("%d",&menu);
    switch(menu){

        case 1:
        system("cls");
        tampilan();
        Posisi(49, 7);
        printf("Create Data",id+1);
        Posisi(27, 10);
        printf("Nama Barang     : ");
        scanf("%s",barang);
        Posisi(27, 11);
        printf("ID Barang       : ");
        scanf("%d",&id);
        Posisi(27, 12);
        printf("Nama Pembeli    : ");
        scanf(" %s",pembeli);
        Posisi(27, 13);
        printf("Jumlah Barang   : ");
        scanf("%d",&jumlah);
        Posisi(27, 14);
        printf("Harga Barang    : ");
        scanf("%d",&harga);
        Posisi(27, 17);
        printf("Menambahkan Data : \n");
        Posisi(27, 18);
        load();

        system("COLOR A");
        menu_create(barang,id,pembeli,jumlah,harga);
        Posisi(27, 20);
        system("pause>nul|echo\tBerhasil ditambahkan. Press Apapun Untuk Ke Menu...");

        system("cls");
        strcpy(hist[history],"Anda Membuka Menu Create Data" );
        history++;
        break;

        case 2:
        system("cls");
        printf("___________________________________________________________________________________________________\n");
        printf("|               Nama Barang\tID Barang\tNama Pembeli\tJumlah Barang\tHarga Barang      |\n");
        printf("|-------------------------------------------------------------------------------------------------|\n");
        menu_read();
        printf("___________________________________________________________________________________________________\n");
        system("pause >nul|echo\tPress Apapun Untuk Ke Menu...");
        system("cls");
        strcpy(hist[history],"Anda Membuka Menu Read Data");
        history++;
        break;

        case 3:sorting();
        printf("       | ----------------------------------------------------------------------------------------------- |\n");
        printf("       | --------------------------::::--::::--:::: TRANSAKSI ::::--::::--::::-------------------------- |\n");
        printf("       | ::::----::::--------------------------- PEMBELIAN BARANG --------------------------::::----:::: |\n");
        printf("       | --------------------------------- TAMPILAN DATA HASIL SORTING --------------------------------- |");
        printf("\n       | ----------------------------------------------------------------------------------------------- |\n");
        printf("       |       Nama Barang\tID Barang\tNama Pembeli\tJumlah Barang\tHarga Barang             |\n");
        tampil();
        printf("       | ----------------------------------------------------------------------------------------------- |\n");
        system("pause >nul|echo\t        Press apapun untuk kembali ke menu...");
        system("cls");
        strcpy(hist[history],"Anda Membuka Menu Sorting Data");
        history++;
        break;

        case 4:
        menu_searching();
        break;

        case 5:
        system("cls");
        tampilan();
        Posisi(39, 7);
        printf("Menghapus data di database toko");
        Posisi(27, 10);
        printf("Masukkan ID data yang hendak di hapus : ");
        scanf("%i", &pil);
        Posisi(27, 12);
        printf("Mencari ID Data : \n");
        Posisi(27, 13);
        load();

        printf("\n");
        del(pil);
        system("COLOR A");
        Posisi(27, 20);
        system("pause >nul | echo Tekan tombol apapun untuk kembali...");
        system("cls");
        strcpy(hist[history],"Admin menghapus data");
        history++;
        break;

        case 6:
        system("cls");
        tampilan();
        Posisi(47, 7);
        printf("Mengupdate Data\n");
        Posisi(27, 10);
        printf("Masukkan ID Barang : ");
        scanf("%i", &id);
        update(id);

        break;

        case 7:
        menu_history();
        break;
        case 8:
        system("cls");
        menu_exit();
        break;
        case 9:
        out();
        printf("\n\n");
        break;}}
    while(menu!=9);
    return 0;}

// menu create data
void menu_create(char barang2[50],int id2,char pembeli2[50],int jumlah2,int harga2){
    current=(struct data*)malloc(sizeof(struct data));

    current->barang=(char*)calloc(strlen(barang2),sizeof(char));
    strncpy(current->barang,barang2,strlen(barang2));

    current->pembeli=(char*)calloc(strlen(pembeli2),sizeof(char));
    strncpy(current->pembeli,pembeli2,strlen(pembeli2));

    current->id=id2;

    current->jumlah=jumlah2;

    current->harga=harga2;
    if(head==NULL){
        head=tail=current;
        head->next=NULL;}
    else{
        tail->next=current;
        tail=current;}
    tail->next=NULL;
    tail=current;}

//update
void update(int id_bar){
char nama_new[50];
    char pembeli_new[50];
    int jum_new;
    int harga_new;
    current = (struct data*)malloc(sizeof(struct data));

    if(head==NULL)
    {
        Posisi(27, 20);
        printf("\nMaaf, data dengan kode transaksi tersebut tidak ada \n");
        system("pause >nul | echo Tekan tombol apapun untuk kembali...");
        system("cls");
      return;


    }

     current=head;
    while(current!=NULL){
    if(current->id==id_bar)
    {
	    //Barang
            Posisi(27, 12);
            printf("Nama Barang baru    : ");
            scanf(" %s", nama_new);
            current->barang=(char*)calloc(strlen(nama_new),sizeof(char)); //bisa hapus
            strncpy(current->barang,nama_new,strlen(nama_new)); //bisa hapus

	    //Pembeli
            Posisi(27, 13);
            printf("Nama Pembeli baru   : ");
            scanf(" %s", pembeli_new);
            current->pembeli=(char*)calloc(strlen(pembeli_new),sizeof(char)); //bisa hapus
            strncpy(current->pembeli,pembeli_new,strlen(pembeli_new)); //bisa hapus

	    //Jumlah Barang
            Posisi(27, 14);
            printf("Jumlah Barang baru  : ");
            scanf("%i", &jum_new);
            current->jumlah=jum_new;

            //harga
            Posisi(27, 15);
            printf("Harga Barang baru   : ");
            scanf("%i", &harga_new);
            current->harga=harga_new;

            Posisi(27, 17);
            printf("Mengupdate Data : \n");
            Posisi(27, 18);
            load();

            system("COLOR A");
            Posisi(27, 20);
            system("pause>nul|echo\tBerhasil ditambahkan. Press Apapun Untuk Ke Menu...");
            system("cls");
            strcpy(hist[history],"Anda Membuka Mengedit Data" );
            history++;
            return;
    }
    current = current->next;

    }
    Posisi(27, 20);
    printf("Maaf, tidak ada data\n\n");
    system("pause >nul | echo Tekan tombol apapun untuk kembali...");
    system("cls");
    }


// menu read data
void menu_read(){
    current=head;
    while(current!=NULL){
    printf("|\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d               |\n",current->barang,current->id,current->pembeli,current->jumlah,current->harga);
    current=current->next;}}

// menu exit data
void menu_exit(){
    FILE*fptr;
    fptr=fopen("data.csv","w");
    current=head;
    while(current!=NULL){
    fprintf(fptr,"Nama Barang =%s\tID Barang =%d\tNama Pembeli =%s\tJumlah Barang =%d\tHarga Barang =%d\n",current->barang,current->id,current->pembeli,current->jumlah,current->harga);
    current=current->next;}
    fclose(fptr);
    return 0;
    }

// menu searching data
void menu_searching(){
    system("cls");
    tampilan();
    Posisi(48, 7);
    printf("Searching Data");
    char buff[20];

    if(head==NULL){
    puts("NOT FOUND 404");
	system("cls");}

    tampilan();
    Posisi(48, 7);
    printf("Searching Data");
    Posisi(27, 9);
    printf("Input Nama Barang yang dicari: ");
    fflush(stdin);
    gets(buff);
    current=head;
    Posisi(27,11);
    printf("Mencari Nama : \n");
    Posisi(27, 12);
    load();

    while(current!=NULL){
    if(strcmp(current->barang,buff)==0){
    system("COLOR A");
    tampilan();
    Posisi(48, 7);
    printf("Searching Data");
    Posisi(27, 12);
    printf(" Nama Barang          : %s",current->barang);
    Posisi(27, 13);
    printf(" ID Barang            : %d",current->id);
    Posisi(27, 14);
    printf(" Nama Pembeli         : %s",current->pembeli);
    Posisi(27, 15);
    printf(" Jumlah barang        : %d",current->jumlah);
    Posisi(27, 16);
    printf(" Harga barang         : %d",current->harga);
    current=current->next;
    printf("\n");}
	else{
	current = current->next;
    printf("\n\n",buff);}}
    Posisi(27, 20);
    system("pause>nul|echo\tPress Apapun Untuk Ke Menu...");
    system("cls");
    strcpy(hist[history],"Anda Membuka Menu Searching Data");
    history++;}

//Sorting
void sorting(){
    system("cls");
    int temp_id;
    char temp_nama [100];
    int temp_harga;
    int temp_jumlah;

    struct data *temp;

    int pilihan;
    printf("       | ------------------------------------------------------------------------------------------------|\n");
    printf("       | -----------------------------------  Urutkan berdasarkan  --------------------------------------|\n");
    printf("       | ------------------------------------------------------------------------------------------------|\n");
                    //pilihan diurutkan berdasarkan apa
    printf("       | -----------------------------------  1. ID Barang         --------------------------------------|\n");
    printf("       | -----------------------------------  2. Nama barang       --------------------------------------|\n");
    printf("       | -----------------------------------  3. Harga barang      --------------------------------------|\n");
    printf("       | -----------------------------------  4. Jumlah barang     --------------------------------------|\n");
    printf("       | ------------------------------------------------------------------------------------------------|\n");
    printf("       | ------------------------------------------------------------------------------------------------|\n");
    printf("        Masukkan pilihan Anda : "); scanf("%d", &pilihan);

    switch(pilihan){
    case 1: //kode transaksi
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->id > temp->id)
                {

                    temp_id = current->id;
                    current->id = temp->id;
                    temp->id = temp_id;

                    strcpy(temp_nama,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama);


                    temp_harga = current->harga;
                    current->harga = temp->harga;
                    temp->harga = temp_harga;


                    temp_jumlah = current->jumlah;
                    current->jumlah = temp->jumlah;
                    temp->jumlah = temp_jumlah;


                }
            }
        }
    break;

    case 2: //nama barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(strcmp(current->barang, temp->barang) > 0)
                {

                    temp_id = current->id;
                    current->id = temp->id;
                    temp->id = temp_id;

                    strcpy(temp_nama,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama);


                    temp_harga = current->harga;
                    current->harga = temp->harga;
                    temp->harga = temp_harga;


                    temp_jumlah = current->jumlah;
                    current->jumlah = temp->jumlah;
                    temp->jumlah = temp_jumlah;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");

    break;

    case 3: //harga barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->harga > temp->harga)
                {

                    temp_id = current->id;
                    current->id = temp->id;
                    temp->id = temp_id;

                    strcpy(temp_nama,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama);


                    temp_harga = current->harga;
                    current->harga = temp->harga;
                    temp->harga = temp_harga;


                    temp_jumlah = current->jumlah;
                    current->jumlah = temp->jumlah;
                    temp->jumlah = temp_jumlah;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    break;

    case 4: //jumlah barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->jumlah > temp->jumlah)
                {

                    temp_id = current->id;
                    current->id = temp->id;
                    temp->id = temp_id;

                    strcpy(temp_nama,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama);


                    temp_harga = current->harga;
                    current->harga = temp->harga;
                    temp->harga = temp_harga;


                    temp_jumlah = current->jumlah;
                    current->jumlah = temp->jumlah;
                    temp->jumlah = temp_jumlah;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    break;


    default:
        printf("\n\n\t\t\t\t               pilihan tidak ada \n\n");
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
        break; // milik case
    }
}

// menu history data
void menu_history(){
    system("cls");
    printf("___________________________________________________________________________________________________\n");
    for(int no_awal=1;no_awal<history;no_awal++){
	printf("\t\t\t\t%d.\t%s\n",no_awal,hist[no_awal]);}
    printf("___________________________________________________________________________________________________\n");

	printf("\n");
    system("pause>nul|echo\tPress Apapun Untuk Ke Menu...");
    system("cls");
    strcpy(hist[history],"Anda Membuka Menu History Data");
    history++;}

// menu Delete Data
void del(int hapus)
{
   current=head;

 if(current==NULL)
   {
       Posisi(27, 15);
       printf("Maaf, data tidak ditemukan");
       return;
   }

   if(current->id==hapus)
   {
       Posisi(27, 15);
       printf("Data Dikosongkan",hapus);
       head=head->next=NULL;

       free(head);
   }


   while(current->next!=NULL)
   {
       if(current->next->id==hapus)
       {
           Posisi(27, 15);
           printf("Data dengan kode transaksi %d telah berhasil dihapus",hapus);
           current->next=current->next->next;
           return;
       }
       current=current->next;
   }
}



//tampilan
void tampilan(){
    Posisi(26, 6);
    printf("\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf\n");
    Posisi(26, 7);
    printf("\xb3                                                        \xb3");
    Posisi(26, 8);
    printf("\xb3--------------------------------------------------------\xb3");
    Posisi(26, 9);
    printf("\xb3                                                        \xb3");
    Posisi(26, 10);
    printf("\xb3                                                        \xb3");
    Posisi(26, 11);
    printf("\xb3                                                        \xb3");
    Posisi(26, 12);
    printf("\xb3                                                        \xb3");
    Posisi(26, 13);
    printf("\xb3                                                        \xb3");
    Posisi(26, 14);
    printf("\xb3                                                        \xb3");
    Posisi(26, 15);
    printf("\xb3                                                        \xb3");
    Posisi(26, 16);
    printf("\xb3                                                        \xb3");
    Posisi(26, 17);
    printf("\xb3                                                        \xb3");
    Posisi(26, 18);
    printf("\xb3                                                        \xb3");
    Posisi(26, 19);
    printf("\xb3--------------------------------------------------------\xb3");
    Posisi(26, 20);
    printf("\xb3                                                        \xb3");
    Posisi(26, 21);
    printf("\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9\n");
}

//tampil
void tampil(){
	struct tm *Sys_T;
	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);
	Sys_T = gmtime(&Tval);
    current=head;
    while(current!=NULL){
    printf("       |\t%s\t\t%d\t\t%s\t\t%d\t\t%d                      |\n",current->barang,current->id,current->pembeli,current->jumlah,current->harga);
    current=current->next;}}

//Loading
void load(){
    int i;
    system("COLOR E");
    for(i=0; i<25;i++){ //untuk buat loading sebanyak 30 bar
            printf("%c",254); //untuk buat bar loading 233 untuk lingkaran, 254 persegi
            Sleep(50); //untuk delaynya
        }
}


//MenuOut
void out(){
    int i;
    system("cls");
    Posisi(45, 10);
    system("COLOR E"); //abuabu
    for(i=0; i<30;i++){ //untuk buat loading sebanyak 30 bar
            printf("%c",248); //untuk buat bar loading 233 untuk lingkaran, 254 persegi
            Sleep(100); //untuk delaynya
    }

    Posisi(55, 8);
    system("COLOR E"); //kuning
    printf("Thank You\n");
    Sleep(500);

}
