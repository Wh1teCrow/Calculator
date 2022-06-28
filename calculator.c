#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

FILE *file_i; 
FILE *file_o;

long int factorial(long int n)           //Реализация функции факториала
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}



struct input_uni{

        int temp;
        int v;              ////////////////////////////UNIVERSAL'NAYA PEREMENNAYA DLYA OPREDELENIYA S CHEM RABOTAT' VECTORAMI, CELIMI CHISLAMI ILI VESH'ESTVENNIMI
        
        struct input_uni *next;
};
typedef struct input_uni input_uni;



struct input_v1{     ///////////////VHODNIE DANNIE DLYA VESH'ESTVENNIH CHISEL
    
      
        float a;           ///////////// 1 CHISLO
        float b;            ////////////// 2 CHISLO
        int o;               ///////////// OPERACIYA
        int temp;            /////////// PEREZAPUSK
        struct input_v1 *next;
      
};
typedef struct input_v1 input_v1;


struct input_v2{     ///////////////VHODNIE DANNIE DLYA VESH'ESTVENNIH CHISEL
    
      
        int a;           ///////////// 1 CHISLO
        int b;            ////////////// 2 CHISLO
        int o;               ///////////// OPERACIYA
        int temp;            /////////// PEREZAPUSK
        struct input_v2 *next;
      
};
typedef struct input_v2 input_v2;

    struct input_v3{           ////////// VHODNIE DANNIE DLYA VECTOROV
        int op_v;               ///////////// OPERACIYA VECTOROV
        int size;               ///////////// RAZMERI VECTOROV
        float *ui;               ///////////// PAMYAT' POD 1 VECTOR
        float *vi;                ///////////// PAMYAT' POD 1 VECTOR
        int temp;
        struct input_v3 *next;
        
    };
typedef struct input_v3 input_v3;

struct rezult{
    int rez;
    

    struct rezult *next;
};
typedef struct rezult rezult;

struct rezult_v{
    float rez_v;

    struct rezult_v *next;
};
typedef struct rezult_v rezult_v;

struct output_v3           ////////// VHODNIE DANNIE DLYA VECTOROV
    {
        float rezi;
        float *rez_vec;
        
        struct output_v3 *next;
        
        
    };
typedef struct output_v3 output_v3;

//INP_PUSH////////////////////////////////////////////////////////////////////////////////
//inp_puch universal
void inp_push_uni(input_uni** head_uni){
    input_uni* list_uni = (input_uni*) malloc(sizeof(input_uni));

    input_uni *last = *head_uni;
    
 
    fscanf(file_i, "%i",&list_uni->v); 
        

    list_uni->next = NULL;
	if(*head_uni == NULL){
		*head_uni = list_uni;
		return ;
	}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = list_uni;
	return ;
}



//push celie
void inp_push_v2(input_v2** head){
    input_v2* list = (input_v2*) malloc(sizeof(input_v2));

    input_v2 *last = *head;
    
 
        fscanf(file_i, "%i",&list->a); 
        fscanf(file_i, "%i", &list->b);
        fscanf(file_i, "%i", &list->o);
        fscanf(file_i,"%i", &list->temp);

    list->next = NULL;
	if(*head == NULL){
		*head = list;
		return ;
	}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = list;
	return ;
}

//push vesh'estvennie
void inp_push_v1(input_v1** head_v1){
    input_v1* list = (input_v1*) malloc(sizeof(input_v1));

    input_v1 *last = *head_v1;
    
 
    fscanf(file_i, "%f", &list->a); 
    fscanf(file_i, "%f", &list->b);
    fscanf(file_i, "%i", &list->o);
    fscanf(file_i,"%i", &list->temp);

    list->next = NULL;
	if(*head_v1 == NULL){
		*head_v1 = list;
		return ;
	}
    while (last->next != NULL){
		last = last->next;
	}
	last->next = list;
	return;

}


//push vectors
void inp_push_vectors(input_v3** head_vector){
    input_v3* list = (input_v3*) malloc(sizeof(input_v3));

    input_v3 *last = *head_vector;
    
    fscanf(file_i, "%i", &list->size);

    list->ui = (float*) malloc(list->size * sizeof(float));
    list->vi = (float*) malloc(list->size * sizeof(float));
    

    for(int j=0;j<list->size;j++){   
        fscanf(file_i, "%f", &(list->ui[j]));
        
                   
                    
    };
    for(int d=0;d<list->size;d++){   
        fscanf(file_i, "%f", &(list->vi[d]));
                   
                    
    };
    fscanf(file_i, "%i", &list->op_v);
    fscanf(file_i,"%i", &list->temp);


    list->next = NULL;
	if(*head_vector == NULL){
		*head_vector = list;
		return ;
	}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = list;
// 	return ;
}

////OUT_PUSH/////////////////////////////////////////////////////////////////

//out_puch_celie chisla
void out_push_cel(rezult** head, int result ){
    rezult* list_o = (rezult*) malloc(sizeof(rezult));
    rezult *last = *head;

    list_o->rez = result;
    list_o->next = NULL;
    if(*head == NULL){
			*head = list_o;
			return;
		}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = list_o;
	return;
}

//out_push_vesh'estvennie
void out_push_v(rezult_v** rez_v_head, float result ){
    rezult_v* list_v = (rezult_v*) malloc(sizeof(rezult_v));
    rezult_v *last = *rez_v_head;

    list_v->rez_v = result;
    list_v->next = NULL;
    if(*rez_v_head == NULL){
			*rez_v_head = list_v;
			return;
		}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = list_v;
	return;
}


void out_push_vector(output_v3** output_v3_head, float *result ){
    output_v3* list_v = (output_v3*) malloc(sizeof(output_v3));
    output_v3 *last = *output_v3_head;


  
    list_v->rez_vec = result;
    
    
    list_v->next = NULL;
    if(*output_v3_head == NULL){
			*output_v3_head = list_v;
			return;
		}

	while (last->next != NULL){
		last = last->next;
	}
	last->next = list_v;
	return;
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


    input_uni* head_uni; // Golova  spiska uni
    input_uni* current_uni; // uni
    input_v2* head; // Golova  spiska vvoda
    input_v2* current; // tekushiy element spiska vvoda
    input_v1* head_v1; // Golova spiska vvoda
    input_v1* current_v1; // tekushiy element spiska vvoda
    input_v3* head_vector;
    input_v3* current_vector;




    rezult* rez_head; // Golova  resultata
	rezult* rez_current; // tekushiy element spiska vivoda
    rezult_v* rez_v_head;
    rezult_v* rez_v_current;
    output_v3* output_v3_head;
    output_v3* output_v3_current;
    rez_v_head = NULL;
    rez_v_current = NULL;
    head = NULL;
    current = NULL;
    head_v1 = NULL;
    current_v1 = NULL;
    rez_head = NULL;
	rez_current = NULL;
    head_uni = NULL;
    current_uni = NULL;
    head_vector = NULL;
    current_vector = NULL;
    output_v3_head = NULL;
    output_v3_current = NULL;
    
    int result_i,j,d;
    float result_f,  st;
	

    printf("Vvedite fail dlya vvoda: ");
    const char *kr_vv[100];
    scanf("%99s", &*kr_vv);
    printf("\nVvedite fail dlya vivoda: ");
    const char *kr_viv[100];
    scanf("\n%99s", &*kr_viv);

    file_i = fopen(kr_vv, "r"); //////////////////////////////////////////////FAIL VHODA OTKRIVAEM///////// 
    inp_push_uni(&head_uni);
     current_uni = head_uni;
    while (feof(file_i) == 0){

		if(current_uni ->v == 1){
            inp_push_v1(&head_v1);
        }
        else if (current_uni ->v == 2){
        inp_push_v2(&head);

        }else if (current_uni ->v == 3){
        inp_push_vectors(&head_vector);
            

        }
    }
 
    fclose(file_i);

    current = head;
    current_v1 = head_v1;
    current_vector = head_vector;
        
           
    if(current_uni ->v == 1){
        switch (current_v1->o)
        {
        case 1:
            result_f = current_v1->a + current_v1 -> b;
            out_push_v(&rez_v_head, result_f);
            break;
        case 2:
            result_f = current_v1->a - current_v1 -> b;
            out_push_v(&rez_v_head, result_f);
            break;
        case 3:
            result_f = current_v1->a * current_v1 -> b;
           out_push_v(&rez_v_head, result_f);
            break;
        case 4:
            
            if (current_v1 -> b == 0){
                fprintf(file_o, "На 0 делить нельзя\n");
            }else{
                 result_f = current_v1 ->a /current_v1 ->b;
                 out_push_v(&rez_v_head, result_f);
            }
            break;
        case 5:
        printf("Эта операция недоступна \n Прочтите инструкцию данной операции\n");
        break;
        case 6:
            if(current_v1 ->b <0){
            current_v1 ->b = current_v1 ->b-current_v1 ->b-current_v1 ->b;
                        
            st = pow((double)current_v1 ->a,(double)current_v1 ->b);
            result_f = 1/st;
            out_push_v(&rez_v_head, result_f);            
                        
            }else{
                result_f = pow((double)current_v1 ->a,(double)current_v1 ->b);                          //<---С помощью <math.h> реализация возведения в степень
                out_push_v(&rez_v_head, result_f);        
             }  
            
        default:
        printf( "error");
            break;
        }
    }
    
    else if (current_uni ->v == 2){
        switch (current->o)
        {
        case 1:
            result_i = current->a + current -> b;
            out_push_cel(&rez_head, result_i);
            break;
        case 2:
            result_i = current->a - current -> b;
            out_push_cel(&rez_head, result_i);
            break;
        case 3:
            result_i = current->a * current -> b;
            out_push_cel(&rez_head, result_i);
            break;
        case 4:
            if (current -> b == 0){
                break;
                
            }else
                result_i = current ->a/current ->b;
                out_push_cel(&rez_head, result_i);
                break;
        case 5:
             if (current ->a > 0  && current ->b ==0){
                result_i = factorial(current ->a);
                out_push_cel(&rez_head, result_i);
                break;
                    
            }else if (current ->a == 0  && current ->b > 0){
                result_i = factorial(current ->b);
                out_push_cel(&rez_head, result_i);
                break;
             
                
            }else if (current ->a == 0 || current ->b >=0){
                printf("Прочтите инструкцию по использованию факториала»\n");
            }
        
        case 6:
        
            if(current ->b <0){
                    
                current ->b = current ->b-current ->b-current ->b;
                    
                st = pow((double)current ->a,(double)current ->b);
                result_i = 1/st;
                out_push_cel(&rez_head, result_i);
                break;    
                }else{
                    result_i = pow((double)current ->a,(double)current ->b);                          //<---С помощью <math.h> реализация возведения в степень
                    out_push_cel(&rez_head, result_i);
                    break;
                }
        default:
         printf( "error");
            break;
        }
    }else if (current_uni ->v == 3){
        float *ez;
        ez = (float*) malloc(current_vector->size * sizeof(float));
        float riv;

        if(current_vector->op_v == 1){
                for(j = 0; j< current_vector->size; j++){
                    (ez[j]) = (current_vector->ui[j])+ (current_vector->vi[j]);         ////////////////VICHISLENIE VEKTOROV

                
                }
                out_push_vector(&output_v3_head,ez);
            }else if(current_vector->op_v == 2){
                for(j = 0; j< current_vector->size; j++){
                    (ez[j]) = (current_vector->ui[j])- (current_vector->vi[j]);
                    
                }
                out_push_vector(&output_v3_head,ez );
            }else if(current_vector->op_v == 3){
                for(j = 0; j< current_vector->size;j++){
                    riv += (current_vector->ui[j])*(current_vector->vi[j]);
                    
                }
                out_push_v(&rez_v_head, riv);
            }
    }



/////////////////////////output/////////////////////////////////
output_v3_current = output_v3_head;
rez_current = rez_head;
rez_v_current = rez_v_head;

file_o = fopen(kr_viv, "w");
    
     if (current_uni ->v == 1){                                                                               ////////////////DLYA VESH'ESTVENNIH//////////////

        if (current_v1->o == 1) fprintf(file_o, "Сумма  %f и %f = %f \n",current_v1->a, current_v1->b, rez_v_current->rez_v);
        else if (current_v1->o == 2) fprintf(file_o, "Разность  %f и %f = %f \n",current_v1->a, current_v1->b, rez_v_current->rez_v);
        else if (current_v1->o == 3) fprintf(file_o, "Произведение  %f и %f = %f \n",current_v1->a, current_v1->b, rez_v_current->rez_v);
        else if (current_v1->o == 4){
            if (current_v1->b == 0){
                    fprintf(file_o, "Деление на 0 невозможно\n");                                     
            }else
                    fprintf(file_o, "Частное %f и %f = %f \n",current_v1->a,current_v1->b,rez_v_current->rez_v);
             }

        if (current_v1->o == 5) fprintf(file_o, "Эта операция недоступна \n Прочтите инструкцию данной операции\n"); 
        if (current_v1->o == 6) fprintf(file_o,"Ответ  = %f \n",rez_v_current->rez_v);
         
     }else if(current_uni ->v == 2){    
                                                                            ////////////////DLYA CELIH////////////////
        if (current->o == 1) fprintf(file_o, "Сумма  %i и %i = %i \n",current->a,current->b, rez_current->rez);  
        else if (current->o == 2) fprintf(file_o, "Разность  %i и %i = %i \n",current->a,current->b, rez_current->rez);
        else if (current->o == 3) fprintf(file_o, "Произведение  %i и %i = %i \n",current->a,current->b,rez_current->rez);
        else if (current->o == 4){
            if (current->b == 0){
                    fprintf(file_o, "Деление на %i невозможно\n", current->b);
            }else
                    fprintf(file_o, "Частное %i и %i = %i \n",current->a,current->b,rez_current->rez);
             }

        else if (current->o == 5){ 
            if (current->a > 0  && current->b ==0){
                fprintf(file_o,"%i! = %li\n", current->a, factorial(current->a));
                    
            }else if (current->a == 0  && current->b > 0){
                fprintf(file_o, "%i! = %li\n", current->b, factorial(current->b));
                
            }else if (current->a == 0 || current->b >=0){
                fprintf(file_o,"Прочтите инструкцию по использованию факториала»\n");
            }
        
        }else if (current->o == 6){ 
            if (current->b<0){
                fprintf(file_o,"Ответ  = %i \n",rez_current->rez);
            }else if(current->b>=0){
                fprintf(file_o, "Ответ  = %i \n",rez_current->rez);
            }
        }
     }else if (current_uni->v == 3){                       //////////////////////////////////////////DLYA VECTOROV////////////////
        
            if(current_vector->op_v == 1){
                    
                    
               
                    fprintf(file_o, "Сумма Вектора(");
                for(int i=0;i<current_vector->size;i++){   
                    fprintf(file_o, "%f ", (current_vector->ui[i]));
                    
                        
                    };
                fprintf(file_o, ")и вектора(");
                for(int d=0;d<current_vector->size;d++){   
                    fprintf(file_o, "%f ", (current_vector->vi[d]));
                    
                        
                    };
                fprintf(file_o, ") =");
                fprintf(file_o, "("); 
                 for(j=0;j<current_vector->size;j++){   
                    fprintf(file_o, "%f ", output_v3_current->rez_vec[j]);
                     
                    
                        
                    };
                    fprintf(file_o, ")");
                    free(current_vector->vi);
                    free(current_vector->ui);
            
            }else if(current_vector->op_v == 2){
                    
                    
                
                    fprintf(file_o, "разность Вектора(");
                for(int i=0;i<current_vector->size;i++){   
                    fprintf(file_o, "%f ", (current_vector->ui[i]));
                    
                        
                    };
                fprintf(file_o, ")и вектора(");
                for(int d=0;d<current_vector->size;d++){   
                    fprintf(file_o, "%f ", (current_vector->vi[d]));
                    
                        
                    };
                fprintf(file_o, ") =");
                fprintf(file_o, "(");
                for(j=0;j<current_vector->size;j++){   
                    fprintf(file_o, "%f ", output_v3_current->rez_vec[j]);
                    
                    
                        
                    };
                    fprintf(file_o, ")");
                    free(current_vector->vi);
                    free(current_vector->ui);

            }else if(current_vector->op_v == 3){
                
                    
                fprintf(file_o, "Скалярное произведение Вектора(");
                for(int i=0;i<current_vector->size;i++){   
                    fprintf(file_o, "%f ", (current_vector->ui[i]));
                    
                        
                    };
                fprintf(file_o, ")и вектора(");
                for(int j=0;j<current_vector->size;j++){   
                    fprintf(file_o, "%f ", (current_vector->vi[j]));
                    
                        
                    };
                fprintf(file_o, ") =%f", rez_v_current->rez_v);
                free(current_vector->vi);
                free(current_vector->ui);
        }
    }
            
     
   
        
                   
                    

// fprintf(file_o, "%i", rezu.rez);
//fprintf(file_o," %i", p.b);

fclose(file_o);


    
    }
