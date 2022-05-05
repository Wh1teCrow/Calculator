#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


long int factorial(long int n)           //Реализация функции факториала
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


int main(){

puts("                                                                                                                 ");
puts("                                                                                                                 ");                                                                                                        
puts("                      ,,   gp                           ll                                                       ");
puts(" 7MM                 7MM   lL  7MM                    l7MM                        mm                             ");
puts("  MM                  MM   l    MM                      MM                        MM                             ");
puts("  MM  ,MP   ,6 Yb.    MM        MM  ,MP  7MM   7MM      MM   7M     MF  ,6lYb.  mmMMmm   apWlWq.      7Mb,od8    ");
puts("  MM ;Y    8)   MM    MM        MM ;Y     MM    MM      MM    VA   ,V  8)   MM    MM    6W     Wb     MM   ll    ");
puts("  MM;Mm     ,pm9MM    MM        MM;Mm     MM    MM      MM     VA ,V    a,pm9MM   MM   AA       M8    MM         ");
puts("  MM  Mb.  8M   MM    MM        MM  Mb.   MM    MM      MM      VVV    vl     vl  MM    YA.   ,A9     MM         ");
puts(".JMML. YA.  Moo9^Yo..JMML.    .JMML. YA.   Mbod YML.  .JMML.    ,V      Moo9^Yo.  lMbmo   Ybmd9     .JMML.       ");
puts("                                                               ,V                                                ");
puts("                                                            OObl                                                 ");
                                     




int o; // Задание переменной означающую номер опреации 
  

int temp = 1;   //переменная, которая на время присваивает себе булево значение
int v;    // ввел ли пользователь вещественное число 
 
 
while (temp == 1){
  printf("%s", "Ваши числа вещественные? \n 1.Да \n 2.Нет\n 3.Операции будут проходить над векторами \n");
  scanf("%i", &v);
  
  
    if (v == 1 ){
        float rez_st;
        float st ;    //Переменная, принимающая значение степени
        float a = 0;     //1 Число, с которым проводятся операции
        float b = 0;     //2 Число, с которым проводятся операции
        printf("%s", "Введите первое число:  ");
        scanf("%f",&a);
        printf("%s", "Введите второе число:  ");
        scanf("%f",&b);
        printf("Выберите номер операции, которую хотите проделать над этими числами:\n 1.Сумма\n 2.Разность\n 3.Произведение\n");                 //<---Набор операций доступных пользователю
        printf(" 4.Деление\n 5.Факториал(Недоступен)\n 6.Возведение в степень\n " );
        
        scanf("%d",&o);
        
        while(o != 1 && o != 2 && o != 3 && o != 4 && o != 5 && o != 6 && o != 7){
                printf("Введите число из списка доступных операций\n ");
                scanf("%d",&o);
            }
       
         
        if(o == 1){
            
            printf("Сумма %f и %f = %f \n",a,b,a+b);
        }else if(o == 2){
            printf("Разность  %f и %f = %f \n",a,b,a-b);
                
        }else if(o == 3){
            printf("Произведение %f и %f = %f \n",a,b,a*b);
                
        }else if(o == 4){
                if (b == 0){
                printf("На 0 делить нельзя\n");
            }else
                printf("Частное %f и %f = %f \n",a,b,a/b);
                    
        }else if(o == 6){
                     if(b <0){
                        b = b-b-b;
                        
                        st = pow((double)a,(double)b);
                        rez_st = 1/st;
                        printf("Ответ  = %f \n",rez_st);
                        
                    }else{
                        st = pow((double)a,(double)b);                          //<---С помощью <math.h> реализация возведения в степень
                        printf("%f в степени %f = %f \n",a,b,st);
                    }    
                      
        }else if(o == 5){
                printf("Эта операция недоступна \n Прочтите инструкцию данной операции\n");
        
        
        }
        
    }else if(v == 2){
        float rez_st;
        int st;    //Переменная, принимающая значение степени
        int a = 0;     //1 Число, с которым проводятся операции
        int b = 0;     //2 Чтсло, с которым проводятся операции
        
        printf("%s", "Введите первое число:  ");
        scanf("%i",&a);
        printf("%s", "Введите второе число:  ");
        scanf("%i",&b);
        printf("Выберите номер операции, которую хотите проделать над этими числами:\n 1.Сумма\n 2.Разность\n 3.Произведение\n");                 //<---Набор операций доступных пользователю
        printf(" 4.Деление\n 5.Факториал\n 6.Возведение в степень\n " );    
        scanf("%d",&o);
        
        while(o != 1 && o != 2 && o != 3 && o != 4 && o != 5 && o != 6 && o != 7){
            printf("Введите число из списка доступных операций \n");
            scanf("%d",&o);
        }
        
        
        if(o == 1){
            
            printf("Сумма %i и %i = %i \n",a,b,a+b);
        }else if(o == 2){
                printf("Разность %i Рё %i = %i \n",a,b,a-b);
                
        }else if(o == 3){
                printf("Произведение %i Рё %i= %i \n",a,b,a*b);
                
        }else if(o == 4){
            if (b == 0){
                printf("Деление на 0 невозможно\n");
            }else
                printf("Частное %i и %i = %i \n",a,b,a/b);
                    
        }else if(o == 6){
            if(b <0){
                    
                b = b-b-b;
                    
                st = pow((double)a,(double)b);
                rez_st = 1/st;
                printf("Ответ  = %f \n",rez_st);
                    
                }else{
                    st = pow((double)a,(double)b);                          //<---С помощью <math.h> реализация возведения в степень
                    printf("%i в степени %i = %i \n",a,b,st);
                }
        }else if(o == 5){
                    
            if (a > 0  && b ==0){
                printf("%i! = %li\n", a, factorial(a));
                    
            }else if (a == 0  && b > 0){
                printf("%i! = %li\n", b, factorial(b));
                
            }else if (a == 0 || b >=0){
                printf("Прочтите инструкцию по использованию факториала»\n");
            }
        }

        
    }else if(v == 3){
            int op_v;
            int size;
            float *ui;
            float *vi;
            float resi;
            int i;
            double s;
            int j;
            int d;
            ui = (int*)malloc(size * sizeof(int));
            vi = (int*)malloc(size * sizeof(int));
            printf("%s", "Введите размерность вектора ");
            scanf("%i", &size);
            
            printf("Введите координаты вектора A: \n");
            for(j=0;j<size;j++){   
                   scanf("%f", &(ui[j]));
                    
                };
            printf("Введите координаты вектора B: \n");
            for(d=0;d<size;d++){   
                   scanf("%f", &(vi[d]));
                    
                };
            printf("Выберите операцию для векторов 1.Сложение векторов 2.Вычитание векторов 3.Умножение векторов \n");
            scanf("%i", &op_v);
            
            if(op_v == 1){
                resi = 0;
                printf("При сложении вектора А и вектора В получается вектор с координатами (");
                for (j=0;j<size;j++){
                    resi = ui[j]+vi[j];
                    printf(" %f ", resi);
                }
                printf(")");
            }else if(op_v == 2){
                resi = 0;
                printf("При вычитании вектора А и вектора В получается вектор с координатами (", resi);
                for (i=0;i<size;i++){
                    resi = ui[i]-vi[i];
                    printf(" %f ", resi);
                }
                printf(")");
            }else if(op_v == 3){
                
                resi = 0;
                for (j=0;j<size;j++){
                    resi+=ui[j]*vi[j];
                }
            printf("Скалярное произведение Вектора А и вектора В равно %f \n",resi);
        }
    
    printf("\nХотите ли вы перезапустить программу?\n Нажмите 1 для перезапуска или любой другой символ для выхода\n");
    temp = 0;
    scanf("%i" , &temp);
    }
 }
}



    


