#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAX 5
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct Antrian{
        int head;
        int tail;
        int data[MAX];
    }antrian;

int isEmpty()
    {
        if(antrian.tail == -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

int isFull()
    {
        if(antrian.tail == MAX -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

void inisialisasi()
    {
        antrian.head=antrian.tail = -1;
    }

    void enqueue(int data)
    {
        if(isEmpty()==1)
        {
            antrian.head=antrian.tail = 0;
            antrian.data[antrian.tail] = data;
            printf("Data %d berhasil diinput!\n",antrian.data[antrian.tail]);
            ext();
        }
        else{


        if(isFull() == 0)
        {
            antrian.tail++;
            antrian.data[antrian.tail] = data;
            printf("data %d berhasil di input\n",antrian.data[antrian.tail]);
            ext();
        }
        }
    }

int dequeue()
    {
        if(isEmpty() == 1)
        {
            printf("Data masih kosong!\n");
            ext();
        }
        else{
            int i;
            int e = antrian.data[antrian.head];
            printf("data %d telah dikeluarkan dari antiran\n",antrian.data[antrian.head]);
            ext();
            for(i=antrian.head;i<=antrian.tail-1;i++)
            {
                antrian.data[i] = antrian.data[i+1];
            }
            antrian.tail--;
                 return e;


        }

    }

void clear()
    {
        antrian.head = antrian.tail = -1;
        printf("Data telah di reset!\n");
        ext();
    }

void print()
    {
        if(isEmpty() == 0)
        {
            for(int i=antrian.head;i<=antrian.tail;i++)
            {
                printf("Data ke %d = %d\n",i,antrian.data[i]);

            }ext();
        }else{
            printf("Data masih kosongg!\n");
            ext();
        }
    }

void qiuqiu()
    {
        int dt;
        inisialisasi();
     int choice;
        do{
            iniqiu:
            printf("1.Enqueue\n");
            printf("2.Dequeue\n");
            printf("3.Print Queue\n");
            printf("4.Clear Queue\n");
            printf("5.Return Main Menu\n");
            printf("Input pilihan:");
            scanf("%d",&choice);
            fflush(stdin);
                switch(choice)
                {
                case 1:
                    system("cls");
                    if(isFull() !=1)
                    {
                        printf("Masukkan data:");
                        scanf("%d",&dt);
                        enqueue(dt);

                    }else{
                        printf("data sudah penuh!\n");
                        ext();

                    }
                    break;
                case 2:
                    system("cls");
                    dequeue();
                    break;
                case 3:
                    system("cls");
                    print();
                    printf("\n");
                    break;
                case 4:
                    system("cls");
                    clear();
                    break;
                case 5:
                    system("cls");
                    main();
                    break;
                default:
                    printf("tidak ada dalam pilihan\n");
                    system("pause");
                    system("cls");
                    goto iniqiu;
                    break;
                }

        }while(choice>0 && choice <6);
        //return 0;

    }
struct Tumpukan{
            char data[5][50];
            int top; //untuk menentukan data paling atas

        }tumpuk;
        //buat fungsi apakah tumpukan masih kosong
int kosong()
{
    if(tumpuk.top == -1)
        {
            return 1;
        }else{
            return 0;
        }
}

        //buat fungsi apakah tumpukan sudah penuh
        //buat fungsi apakah tumpukan sudah penuh
        int Penuh()
        {
            if(tumpuk.top == MAX-1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }

        void initiate()
        {
            //decalare bahwa tumpukan masih kosong
            tumpuk.top = -1;
        }

        void push()
        {
            char temp[30];
            if(Penuh() != 1)
            {
                tumpuk.top++;
                printf("Masukkan data:");
                scanf("%[^\n]",&temp);
                strcpy(tumpuk.data[tumpuk.top],temp);
                printf("Data %s berhasil di input\n",tumpuk.data[tumpuk.top]);
                ext();
            }else{
                printf("Data sudah penuh");
                ext();
            }

        }
        void ext()
        {
            system("pause");
            system("cls");
        }

        void pop()
        {
            if(kosong() != 1)
            {
                printf("Data %s telah dibuang\n",tumpuk.data[tumpuk.top]);
                tumpuk.top--;
                ext();

            }else{
                printf("Data masih kosong\n");
                ext();
            }
        }

        void printData()
        {
            if(kosong() !=1)
            {
                for(int i=tumpuk.top;i>=0;i--)
                {
                    printf("Data Stack ke %d :%s\n",i,tumpuk.data[i]);
                }ext();
            }else{
                printf("Data masih kosong\n");
            }
        }
        void stack()
        {
        initiate();
        int choice;
        do{
            //system("cls");
            inistack:
            printf("1.Push Stack\n");
            printf("2.Pop Stack\n");
            printf("3.Print Stack\n");
            printf("4.Clear Stack\n");
            printf("5.Return Main Menu\n");
            printf("Input pilihan:");
            scanf("%d",&choice);
            fflush(stdin);
                switch(choice)
                {
                case 1:
                    system("cls");
                    push();
                    break;
                case 2:
                    system("cls");
                    pop();
                    break;
                case 3:
                    system("cls");
                    printData();
                    break;
                case 4:
                    system("cls");
                    if(kosong())
                    {
                        printf("Data masih kosong!,tidak bisa reset\n");
                        ext();
                    }
                    else{
                          initiate();
                    printf("Data telah di reset!\n");
                    ext();
                    }

                    break;
                case 5:
                    main();
                default:
                    printf("tidak ada dalam pilihan\n");
                    system("pause");
                    system("cls");
                    goto inistack;
                    break;
                }

        }while(choice >0 && choice < 6);
    }

void main()
{
    int inMenu,y=1;
    char pil;

    system("mode con: cols=120 lines=30");
    system("color F8");
    system("cls");
    do{
    if(y==0){
         y++;
         continue;
    }
        if(y==4){
            y--;
            continue;
        }
    gotoxy(0,2);
    printf("   ");
    for(int a=0;a<41;a++){printf("+");}
    printf("\n   | >>    Tugas Quiz Stack and Queue   << |\n   ");
    for(int a=0;a<41;a++){printf("+");}
    printf("\n   |                                       |\n");
    printf("   |           1. Stack String             |\n");
    printf("   |           2. Queue Integer            |\n");
    printf("   |           3. Exit Program             |\n");
    printf("   |                                       |\n   ");
    for(int a=0;a<41;a++){printf("+");}
    gotoxy(8,5+y);printf("==>");
            pil=getch();
            switch(pil){
            case 72:
                y--;
                break;
            case 80:
                y++;
                break;
            default:
                break;
    }
    }while((int)pil!=13);
    inMenu=y;
    system("cls");

    switch (inMenu)
    {
    case 1:
        stack();
        break;
    case 2:
        qiuqiu();
        break;
    case 3:
        printf("\nTERIMA KASIH ~ GOODLUCK\n");
        system("cls");
        break;
    }
}
