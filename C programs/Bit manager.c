/*Practica No.13
  Carmona Escalante Nadia E.
  P.E.

  Leer 2 numeros de la linea de comandos:

  -mostrar un menu que permita realizar las siguientes opciones:

   1) OR entre los parametros
   2) AND
   3) XOR
   4) Rotar a la izquierda n bits.
   5) Rotar a la derecha n bits.
   6) Enmascaramiento .
*/


#include<stdio.h>
#include<conio.h>

void menuP(int, int);  //se imprime el 1er menu
void maskP(int, int);   //funcion para la mascara
void maskM();          //menu con mascara

int main (int n, char *par[])
{
	int a,b,num;  //a,b parametros para comparacion,num es para los bits.
	char st[3][20]={'\x0'};
	char key;

	a=atoi(par[1]);
	b=atoi(par[2]);


	itoa(a,st[0],2);
	itoa(b,st[1],2);


 do
 {
   menuP(a,b);
   key = getch();

   switch(key)
	 {
	   case '1': printf("a=%d | b=%d = %d\n", a,b,a|b );
		     itoa(a|b,st[3],2);
		     printf("a=%s | b=%s = %s\n", st[0],st[1],st[3]);
		     getch();break;
	   case '2': printf("%d & %d = %d\n",a,b,a&b);
		     itoa(a&b,st[3],2);
		     printf("a=%s & b=%s = %s\n", st[0],st[1],st[3]);
		     getch();break;
	   case '3': printf("%d ^ %d = %d\n",a,b,a^b);
		     itoa(a^b,st[3],2);
		     printf("a=%s ^ b=%s = %s\n", st[0],st[1],st[3]);
		     getch();break;
	   case '4': printf("\ncuantos bits?: ");
		     scanf("%d", &num);
		     printf("\n\na = %db = %d",a,b);
		     printf("\na = %sb = %s",st[0],st[1]);
		     a <<= num;
		     b <<= num;
		     itoa(a,st[0],2);
		     itoa(b,st[1],2);
		     printf("\n\na = %db = %d",a,b);
		     printf("\na = %sb = %s",st[0],st[1]);
		     getch();break;
	    case '5':printf("\nCuantos bits?: ");
		     scanf("%d", &num);
		     printf("\n\na = %db = %d",a,b);
		     printf("\n\na = %sb = %s",st[0],st[1]);
		     a >>= num;
		     b >>= num;
		     itoa(a,st[0],2);
		     itoa(b,st[1],2);
		     printf("\n\na = %d\nb = %d",a,b);
		     printf("\n\na = %s\nb = %s",st[0],st[1]);
		     getch();break;
	    case '6': maskP(a,b);break;


		 }

 }while(key!= '7');

}

void menuP(int a,int b)
{

	clrscr();


	puts("1)OR");
	puts("2)AND");
	puts("3)XOR");
	puts("4)Rotar a la izquierda n bits");
	puts("5)Rotar a la derecha n bits");
	puts("6)Enmascaramiento con AND, OR, XOR");
	puts("7)Salir");

}
void maskP(int a,int b)
{
 int mask=126; //1111110
 char key;
 char st[2][20];

 do
 {

   maskM();
   key= getch();

   switch(key)
	 {


	     case '1': itoa(a,st[0],2);
		       itoa(b,st[1],2);
		       printf("\na = %d,a = %sb = %d,b = %s",a,st[0],b,st[1]);
		       itoa(a&mask,st[0],2);
		       itoa(b&mask,st[1],2);
		       printf("enmascaramiento con AND es: a = %s, b = %s ", st[0],st[1]);
		       getch();break;
	     case '2': itoa(a,st[0],2);
		       itoa(b,st[1],2);
		       printf("\na = %d,a = %sb = %d,b = %s",a,st[0],b,st[1]);
		       itoa(a|mask,st[0],2);
		       itoa(b|mask,st[1],2);
		       printf("\n enmascaramiento con OR es: a = %s, b = %s ", st[0],st[1]);
		       getch();break;
	     case '3': itoa(a,st[0],2);
		       itoa(b,st[1],2);
		       printf("\na = %d,a = %s\tb = %d,b = %s",a,st[0],b,st[1]);
		       itoa(a^mask,st[0],2);
		       itoa(b^mask,st[1],2);
		       printf("\nenmascaramiento con XOR es: a = %s, b = %s ", st[0],st[1]);
		       getch();break;

		}




 }while(key!= '4');


}

void maskM()
{
	clrscr();

	puts("La mascara es 1111110");
	puts("1)AND");
	puts("2)OR");
	puts("3)XOR");
	puts("4)Regresar");

}
