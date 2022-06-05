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
                                     

int k;
FILE *file_i; 
FILE *file_o;
int o; // Задание переменной означающую номер опреации 
  

int temp = 1;   //переменная, которая на время присваивает себе булево значение
int v;    // ввел ли пользователь вещественное число 
 
 
while (temp == 1){
 
  printf("%s", "Ваши числа вещественные? \n 1.Да \n 2.Нет\n 3.Операции будут проходить над векторами \n");
  
  file_i = fopen("input.txt", "r");
  file_o = fopen("output.txt", "w");
  fscanf(file_i,"\n%i", &v);
  
  
    if (v == 1 ){
        float rez_st;
        float st ;    //Переменная, принимающая значение степени
        float a = 0;     //1 Число, с которым проводятся операции
        float b = 0;     //2 Число, с которым проводятся операции
        printf("%s", "Введите первое число:  ");
        fscanf(file_i, "%f", &a);
        printf("%s", "Введите второе число:  ");
        fscanf(file_i, "%f", &b);;
        printf("Выберите номер операции, которую хотите проделать над этими числами:\n 1.Сумма\n 2.Разность\n 3.Произведение\n");                 //<---Набор операций доступных пользователю
        printf(" 4.Деление\n 5.Факториал(Недоступен)\n 6.Возведение в степень\n " );
        
        fscanf(file_i, "%i", &o);
        
        while(o != 1 && o != 2 && o != 3 && o != 4 && o != 5 && o != 6 && o != 7){
                printf("Введите число из списка доступных операций\n ");
                fscanf(file_i, "%i", &o);
            }
       
         
        if(o == 1){
            
            fprintf(file_o, "Сумма  %f и %f = %f \n",a,b,a+b);
        }else if(o == 2){
            fprintf(file_o, "Разность  %f и %f = %f \n",a,b,a-b);
                
        }else if(o == 3){
            fprintf(file_o, "Произведение %f и %f = %f \n",a,b,a*b);
                
        }else if(o == 4){
                if (b == 0){
                fprintf(file_o, "На 0 делить нельзя\n");
            }else
                fprintf(file_o, "Частное %f и %f = %f \n",a,b,a/b);
                    
        }else if(o == 6){
                     if(b <0){
                        b = b-b-b;
                        
                        st = pow((double)a,(double)b);
                        rez_st = 1/st;
                        fprintf(file_o,"Ответ  = %f \n",rez_st);
                        
                    }else{
                        st = pow((double)a,(double)b);                          //<---С помощью <math.h> реализация возведения в степень
                        fprintf(file_o, "%f в степени %f = %f \n",a,b,st);
                    }    
                      
        }else if(o == 5){
                fprintf(file_o, "Эта операция недоступна \n Прочтите инструкцию данной операции\n");
        
        
        }
        
    }else if(v == 2){
        float rez_st;
        int st;    //Переменная, принимающая значение степени
        int a = 0;     //1 Число, с которым проводятся операции
        int b = 0;     //2 Чтсло, с которым проводятся операции
        
        printf("%s", "Введите первое число:  ");
        fscanf(file_i, "%i", &a);
        printf("%s", "Введите второе число:  ");
        fscanf(file_i, "%i", &b);
        printf("Выберите номер операции, которую хотите проделать над этими числами:\n 1.Сумма\n 2.Разность\n 3.Произведение\n");                 //<---Набор операций доступных пользователю
        printf(" 4.Деление\n 5.Факториал\n 6.Возведение в степень\n " );    
        fscanf(file_i, "%i", &o);
        
        while(o != 1 && o != 2 && o != 3 && o != 4 && o != 5 && o != 6 && o != 7){
            printf("Введите число из списка доступных операций \n");
            fscanf(file_i, "%i", &o);
        }
        
        
        if(o == 1){
            
            fprintf(file_o, "Сумма %i и %i = %i \n",a,b,a+b);
        }else if(o == 2){
                fprintf(file_o, "Разность %i и %i = %i \n",a,b,a-b);
                
        }else if(o == 3){
                fprintf(file_o, "Произведение %i и %i= %i \n",a,b,a*b);
                
        }else if(o == 4){
            if (b == 0){
                fprintf(file_o, "Деление на 0 невозможно\n");
            }else
                fprintf(file_o, "Частное %i и %i = %i \n",a,b,a/b);
                    
        }else if(o == 6){
            if(b <0){
                    
                b = b-b-b;
                    
                st = pow((double)a,(double)b);
                rez_st = 1/st;
                fprintf(file_o, "Ответ  = %f \n",rez_st);
                    
                }else{
                    st = pow((double)a,(double)b);                          //<---С помощью <math.h> реализация возведения в степень
                    fprintf(file_o, "%i в степени %i = %i \n",a,b,st);
                }
        }else if(o == 5){
                    
            if (a > 0  && b ==0){
                fprintf(file_o,"%i! = %li\n", a, factorial(a));
                    
            }else if (a == 0  && b > 0){
                fprintf(file_o, "%i! = %li\n", b, factorial(b));
                
            }else if (a == 0 || b >=0){
                fprintf(file_o,"Прочтите инструкцию по использованию факториала»\n");
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
           
           
            fscanf(file_i, "%i", &size);
            
            ui = (float*) malloc(size * sizeof(float));
           
            vi = (float*) malloc(size * sizeof(float));
            printf( "%s", "Введите размерность вектора ");
            
            
            printf("Введите координаты вектора A: \n");
            for(j=0;j<size;j++){   
                   fscanf(file_i, "%f", &(ui[j]));
                   
                    
                };
                
            printf("Введите координаты вектора B: \n");
            for(d=0;d<size;d++){   
                   fscanf(file_i, "%f", &(vi[d]));
                   
                    
                };
                
            printf("Выберите операцию для векторов 1.Сложение векторов 2.Вычитание векторов 3.Умножение векторов \n");
            fscanf(file_i, "%i", &op_v);
            
            if(op_v == 1){
                    resi = 0;
                    
               
                    fprintf(file_o, "Сумма Вектора(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (ui[j]));
                    
                        
                    };
                fprintf(file_o, ")и вектора(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (vi[j]));
                    
                        
                    };
                fprintf(file_o, ") =");
                fprintf(file_o, "("); 
                 for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (ui[j])- (vi[j]));
                     
                    
                        
                    };
                    fprintf(file_o, ")");
                    free(vi);
                    free(ui);
            
            }else if(op_v == 2){
                    resi = 0;
                    
                
                    fprintf(file_o, "разность Вектора(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (ui[j]));
                    
                        
                    };
                fprintf(file_o, ")и вектора(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (vi[j]));
                    
                        
                    };
                fprintf(file_o, ") =");
                fprintf(file_o, "(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (ui[j])- (vi[j]));
                    
                    
                        
                    };
                    fprintf(file_o, ")");
                    free(vi);
                    free(ui);

            }else if(op_v == 3){
                
                    resi = 0;
                    for (j=0;j<size;j++){
                        resi+=ui[j]*vi[j];
                    }
                fprintf(file_o, "Скалярное произведение Вектора(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (ui[j]));
                    
                        
                    };
                fprintf(file_o, ")и вектора(");
                for(j=0;j<size;j++){   
                    fprintf(file_o, "%f ", (vi[j]));
                    
                        
                    };
                fprintf(file_o, ") =%f", resi);
                free(vi);
                free(ui);
        }
    
    printf("\nХотите ли вы перезапустить программу?\n Нажмите 1 для перезапуска или любой другой символ для выхода\n");

    }
    temp = 0;
    
    fscanf(file_i,"%i ", &temp);
    
    fclose(file_i);
    fclose(file_o);
 }

}


    


