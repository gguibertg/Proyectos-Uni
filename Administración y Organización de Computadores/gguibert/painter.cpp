/***************************************************************************
 *   Copyright (C) 2020 by pilar                                           *
 *   pilarb@unex.es                                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "painter.h"

/*Gabriel F. Guiberteau García*/

void painter::borrar(uchar * img, uchar color)
{
    asm volatile(

        "mov %0, %%rsi ;"       /*dirImg = img*/
        "mov %1, %%dl ;"        /*color*/

        "mov $640, %%rcx ;"
        "imul $480, %%rcx ;"    /*nP = 640*480*/

        "mov $0, %%rbx ;"       /*p = 0*/

            "BucleBorrar:"

                "mov %%dl, (%%rsi, %%rbx) ;"    /*[dirImg + p] = color*/

                "inc %%rbx ;"                   /*p++*/
                "cmp %%rcx, %%rbx ;"
                "jb BucleBorrar ;"

        :
        : "m" (img), "m" (color)
        : "%rbx", "%rcx","%rdx", "%rsi", "memory"

    );

}

void painter::modoLibre(uchar * img, int cI, int fI, int grosor, uchar color)
{
    asm volatile(
                
        "mov %0, %%rsi ;"
        "movsxd %1, %%rbx ;"
        "movsxd %2, %%rax ;"
        "movsxd %3, %%rcx ;"
        "mov %4, %%dl ;"
                
        "imul $640, %%rax ;"
        "add %%rbx, %%rax ;"
        "add %%rax, %%rsi ;"
                
        "mov $0, %%rax	;"
                
            "bModoLapizFilas:"
                
                "mov $0, %%rbx	;"
                
                    "bModoLapizColumnas:"
                
                        "mov %%dl, (%%rsi, %%rbx) ;"

                        "inc %%rbx ;"
                        "cmp %%rcx, %%rbx ;"
                        "jl bModoLapizColumnas ;"
                
                    "add $640, %%rsi ;"

                    "inc %%rax ;"
                    "cmp %%rcx, %%rax ;"
                    "jl bModoLapizFilas ;"
                
        :
        : "m" (img), "m" (cI), "m" (fI), "m" (grosor), "m" (color)
        : "%rax","%rbx", "%rcx", "%rdx", "%rsi", "memory"
    );
}


void painter::linea(uchar * img, int c1, int f1, int c2, int f2, int grosor, uchar color)
{
	
    asm volatile(

        "mov %0, %%rsi ;"       /*dirImg = img*/
        "movsxd %1, %%r8 ;"     /*c1*/
        "movsxd %2, %%r9 ;"     /*f1*/
        "movsxd %3, %%r10 ;"    /*c2*/
        "movsxd %4, %%r11 ;"    /*f2*/
        "movsxd %5, %%rcx ;"    /*grosor*/
        "mov %6, %%dl ;"       /*color*/

        "mov %%r10, %%r12 ;"
        "sub %%r8, %%r12 ;"     /*dC*/

        "mov %%r11, %%r13 ;"
        "sub %%r9, %%r13 ;"     /*dF*/

        "cmp %%r13, %%r12 ;"
        "jle NoCumpleIfLinea ;"

        "mov %%r8, %%r11 ;"     /*c = c1*/

            "PrimerBucleLinea: "

                "mov %%r11, %%rax ;"
                "sub %%r8, %%rax ;"
                "imul %%r13 ;"
                "idiv %%r12 ;"
                "add %%r9, %%rax ;"     /*f*/

                "mov %%rax, %%rbx ;"
                "imul $640, %%rbx ;"
                "add %%r11, %%rbx ;"    /*offLinea*/

                "mov $0, %%r14 ;"       /*g = 0*/

                    "SegundoBucleLinea: "

                        "mov %%dl, (%%rsi, %%rbx) ;"        /*[dirImg + offLinea] = color*/

                        "add $640, %%rbx ;"                 /*offLinea = offLinea + 640*/

                        "inc %%rax ;"                       /*f++*/
                        "inc %%r14 ;"                       /*g++*/

                        "cmp %%rcx, %%r14 ;"
                        "jge FinSegundoBucleLinea ;"
                        "cmpq $480, %%rax ;"
                        "jl SegundoBucleLinea ;"

                     "FinSegundoBucleLinea: "

                        "inc %%r11 ;"       /*c++*/

                        "cmp %%r10, %%r11 ;"
                        "jl PrimerBucleLinea ;"
                        "jmp FinLinea ;"

        "NoCumpleIfLinea: "

            "mov %%r9, %%r10 ;"     /*f = f1*/

                "TercerBucleLinea: "

                    "mov %%r10, %%rax ;"
                    "sub %%r9, %%rax ;"
                    "imul %%r12 ;"
                    "idiv %%r13 ;"
                    "add %%r8, %%rax ;"         /*c*/

                    "mov %%r10, %%rbx ;"
                    "imul $640, %%rbx ;"
                    "add %%rax, %%rbx ;"        /*offLinea*/

                    "mov $0, %%r14 ;"           /*g = 0*/

                        "CuartoBucleLinea: "

                            "mov %%dl, (%%rsi, %%rbx) ;"        /*[dirImg + offLinea] = color*/

                            "inc %%rbx ;"                       /*offLinea++*/
                            "inc %%rax ;"                       /*c++*/

                            "inc %%r14 ;"                       /*g++*/

                            "cmp %%rcx, %%r14 ;"
                            "jge FinCuartoBucleLinea ;"
                            "cmpq $640, %%rax ;"
                            "jl CuartoBucleLinea ;"

                         "FinCuartoBucleLinea: "

                            "inc %%r10 ;"           /*f++*/
                            "cmp %%r11, %%r10 ;"
                            "jl TercerBucleLinea ;"

        "FinLinea :"

        :
        : "m" (img), "m" (c1), "m" (f1), "m" (c2), "m" (f2), "m" (grosor), "m" (color)
        : "%rax", "%rbx", "%rcx","%rdx","%rsi", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "memory"
    );
	

}



void painter::rectangulo(uchar * img, int c1, int f1, int c2, int f2, int grosor, uchar color)
{
	
    asm volatile(

        "mov %0, %%rsi ;"         /*dirImg = img*/
        "movsxd %1, %%r8 ;"       /*c1*/
        "movsxd %2, %%r9 ;"       /*f1*/
        "movsxd %3, %%r10 ;"      /*c2*/
        "movsxd %4, %%r11 ;"      /*f2*/
        "movsxd %5, %%rcx ;"      /*grosor*/
        "mov %6, %%dl ;"          /*color*/

        "mov %%r8, %%rax ;"       /*c = c1*/

            "PrimerBucleRectangulo: "

                "mov %%r9, %%rbx ;"
                "imul $640, %%rbx ;"
                "add %%rax, %%rbx ;"        /*offLinea*/

                "mov %%r9, %%r12 ;"         /*f = f1*/

                    "SegundoBucleRectangulo: "

                        "mov %%dl, (%%rsi, %%rbx) ;"    /*[dirImg + offLinea] = color*/
                        "add $640, %%rbx ;"             /*dirImg = dirImg + 640*/

                        "inc %%r12 ;"                   /*f++*/
                        "mov %%r9, %%r13 ;"
                        "add %%rcx, %%r13 ;"            /*f1 + grosor*/
                        "cmp %%r13, %%r12 ;"
                        "jae FinSegundoBucleRectangulo ;"
                        "cmpq $480, %%r12 ;"
                        "jb SegundoBucleRectangulo ;"

                    "FinSegundoBucleRectangulo: "

                    "mov %%r11, %%rbx ;"
                    "imul $640, %%rbx ;"
                    "add %%rax, %%rbx ;"            /*offLinea*/

                    "mov %%r11, %%r12 ;"            /*f = f2*/

                    "TercerBucleRectangulo: "

                        "mov %%dl, (%%rsi, %%rbx) ;"    /*[dirImg + offLinea] = color*/
                        "add $640, %%rbx ;"             /*dirImg = dirImg + 640*/

                        "inc %%r12 ;"                   /*f++*/
                        "mov %%r11, %%r13 ;"
                        "add %%rcx, %%r13 ;"            /*f2 + grosor*/
                        "cmp %%r13, %%r12 ;"
                        "jae FinTercerBucleRectangulo ;"
                        "cmpq $480, %%r12 ;"
                        "jb TercerBucleRectangulo ;"

                     "FinTercerBucleRectangulo: "

                     "inc %%rax ;"                      /*c++*/
                     "cmp %%r10, %%rax ;"
                     "jbe PrimerBucleRectangulo ;"

        "mov %%r9, %%rax ;"       /*f = f1*/

            "CuartoBucleRectangulo: "

                "cmpq $480, %%rax ;"
                "jae NoCumpleIfRectangulo ;"

                "mov %%rax, %%rbx ;"
                "imul $640, %%rbx ;"
                "add %%r8, %%rbx ;"         /*offLinea*/

                "mov %%r8, %%r12 ;"         /*c = c1*/

                    "QuintoBucleRectangulo: "


                        "mov %%dl, (%%rsi, %%rbx) ;"    /*[dirImg + offLinea] = color*/
                        "inc %%rbx ;"                   /*offLinea++*/

                        "inc %%r12 ;"                   /*c++*/
                        "mov %%r8, %%r13 ;"
                        "add %%rcx, %%r13 ;"            /*c1 + grosor*/
                        "cmp %%r13, %%r12 ;"
                        "jae FinQuintoBucleRectangulo ;"
                        "cmpq $640, %%r12 ;"
                        "jb QuintoBucleRectangulo ;"

                    "FinQuintoBucleRectangulo: "

                    "mov %%rax, %%rbx ;"
                    "imul $640, %%rbx ;"
                    "add %%r10, %%rbx ;"         /*offLinea*/

                    "mov %%r10, %%r12 ;"         /*c = c2*/

                        "SextoBucleRectangulo :"

                            "mov %%dl, (%%rsi, %%rbx) ;"    /*[dirImg + offLinea] = color*/
                            "inc %%rbx ;"                   /*offLinea++*/

                            "inc %%r12 ;"                   /*c++*/
                            "mov %%r10, %%r13 ;"
                            "add %%rcx, %%r13 ;"            /*c2 + grosor*/
                            "cmp %%r13, %%r12 ;"
                            "jae NoCumpleIfRectangulo ;"
                            "cmpq $640, %%r12 ;"
                            "jb SextoBucleRectangulo ;"

            "NoCumpleIfRectangulo :"

                "inc %%rax ;"           /*f++*/
                "mov %%r11, %%r13 ;"
                "add %%rcx, %%r13 ;"
                "cmp %%r13, %%rax ;"
                "jb CuartoBucleRectangulo ;"

        :
        : "m" (img), "m" (c1), "m" (f1), "m" (c2), "m" (f2), "m" (grosor), "m" (color)
        : "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "memory"
    );


}


void painter::circulo(uchar * img, int c_c, int f_c, int r, int grosor, uchar color)
{
    // En caso de implementar el procedimiento utilizando instrucciones de FPU,
    // esta variable se debe usar para intercambio de datos entre CPU y FPU.
    // Su uso no es necesario si se utilizan las instrucciones sobre escalares de SSE.
    int aux;

    asm volatile(
        ";"

        :
        : "m" (img), "m" (c_c), "m" (f_c), "m" (r), "m" (grosor), "m" (color), "m" (aux)
        : "memory"
    );

}



void painter::rellenar(uchar * img, int c, int f, uchar color)
{
    asm volatile(
        ";"

        :
        : "m" (img), "m" (c), "m" (f), "m" (color)
        : "memory"

    );


}



void painter::copiar(uchar * img, uchar * buffer, int c, int f, int w, int h)
{
    asm volatile(

        "mov %0, %%rsi ;"       /*dirImg = img*/
        "mov %1, %%rdi ;"       /*dirBuffer = buffer*/
        "movsxd %2, %%rax ;"    /*C*/
        "movsxd %3, %%r8 ;"     /*F*/
        "movsxd %4, %%rcx ;"    /*W*/
        "movsxd %5, %%rdx ;"    /*H*/

        "imul $640, %%r8 ;"
        "add %%r8, %%rsi ;"     /*dirImg = dirImg + f*640*/

        "mov $0, %%r8 ;"        /*cF = 0*/

            "PrimerBucleCopiar: "

                "mov %%rax, %%rbx ;"    /*offC = c*/

                "mov $0, %%r9 ;"        /*cC = 0*/

                    "SegundoBucleCopiar: "

                        "mov (%%rsi, %%rbx), %%r10 ;"
                        "mov %%r10, (%%rdi) ;"          /*[dirBuffer] = [dirImg + offC]*/
                        "inc %%rdi ;"                   /*dirBuffer++*/
                        "inc %%rbx ;"                   /*offC++*/

                        "inc %%r9 ;"                    /*cC++*/
                        "cmp %%rcx, %%r9 ;"
                        "jb SegundoBucleCopiar ;"

                    "add $640, %%rsi ;"     /*dirImg = dirImg + 640*/

                    "inc %%r8 ;"            /*cF++*/
                    "cmp %%rdx, %%r8 ;"
                    "jb PrimerBucleCopiar ;"

        :
        : "m" (img), "m" (buffer), "m" (c), "m" (f), "m" (w), "m" (h)
        : "%rax", "%rbx", "%rcx","%rdx", "%r8", "%r9", "%r10", "memory"

    );

}

void painter::cortar(uchar * img, uchar * buffer, int c, int f, int w, int h, uchar cFondo)
{
    asm volatile(

        "mov %0, %%rsi ;"       /*dirImg = img*/
        "mov %1, %%rdi ;"       /*dirBuffer = buffer*/
        "movsxd %2, %%r8 ;"     /*C*/
        "movsxd %3, %%r9 ;"     /*F*/
        "movsxd %4, %%rcx ;"    /*W*/
        "movsxd %5, %%rax ;"    /*H*/
        "mov %6, %%dl ;"        /*cFondo*/

        "imul $640, %%r9 ;"
        "add %%r9, %%rsi ;"     /*dirImg = dirImg + f*640*/

        "mov $0, %%r9 ;"        /*cF = 0*/

            "PrimerBucleCortar: "

                "mov %%r8, %%rbx ;"     /*offC = c*/

                "mov $0, %%r10 ;"       /*cC = 0*/

                    "SegundoBucleCortar: "

                        "mov (%%rsi, %%rbx), %%r11 ;"
                        "mov %%r11, (%%rdi) ;"              /*[dirBuffer] = [dirImg + offC]*/
                        "mov %%dl, (%%rsi, %%rbx) ;"        /*[dirImg + offC] = cFondo*/
                        "inc %%rdi ;"                       /*dirBuffer++*/
                        "inc %%rbx ;"                       /*offC++*/

                        "inc %%r10 ;"                       /*cC++*/
                        "cmp %%rcx, %%r10 ;"
                        "jb SegundoBucleCortar ;"

                    "add $640, %%rsi ;"

                    "inc %%r9 ;"                /*cF++*/
                    "cmp %%rax, %%r9 ;"
                    "jb PrimerBucleCortar ;"


        :
        : "m" (img), "m" (buffer), "m" (c), "m" (f), "m" (w), "m" (h), "m" (cFondo)
        : "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "rdi", "%r8", "%r9", "%r10", "%r11", "memory"

    );


}

void painter::pegar(uchar * img, uchar * buffer, int c, int f, int w, int h)
{
    asm volatile(

        "mov %0, %%rsi ;"       /*dirImg = img*/
        "mov %1, %%rdi ;"       /*dirBuffer = buffer*/
        "movsxd %2, %%rax ;"    /*C*/
        "movsxd %3, %%r8 ;"     /*F*/
        "movsxd %4, %%rcx ;"    /*W*/
        "movsxd %5, %%rdx ;"    /*H*/

        "mov %%r8, %%r9 ;"
        "imul $640, %%r9 ;"
        "add %%r9, %%rsi ;"     /*dirImg = dirImg + f*640*/

        "mov $0, %%r9 ;"        /*cF = 0*/

            "PrimerBuclePegar: "

                "mov %%rax, %%rbx ;"    /*offC = c*/

                "mov $0, %%r10 ;"        /*cC = 0*/

                    "SegundoBuclePegar: "

                        "cmpq $640, %%rbx ;"
                        "jae NoCumpleIfPegar ;"
                        "mov (%%rdi), %%r11b ;"
                        "mov %%r11b, (%%rsi, %%rbx) ;"       /*[dirImg + offC] = [dirBuffer]*/

                        "NoCumpleIfPegar :"

                            "inc %%rdi ;"       /*dirBuffer++*/
                            "inc %%rbx ;"       /*offC++*/

                        "inc %%r10 ;"                        /*cC++*/
                        "cmp %%rcx, %%r10 ;"
                        "jb SegundoBuclePegar ;"

                    "add $640, %%rsi ;"     /*dirImg = dirImg + 640*/

                    "inc %%r9 ;"            /*cF++*/
                    "cmp %%rdx, %%r9 ;"
                    "jae FinPegar ;"
                    "mov %%r8, %%r11 ;"
                    "add %%r9, %%r11 ;"
                    "cmpq $480, %%r11 ;"
                    "jb PrimerBuclePegar ;"

        "FinPegar: "

        :
        : "m" (img), "m" (buffer), "m" (c), "m" (f), "m" (w), "m" (h)
        : "%rax","%rbx", "%rcx","%rdx", "%rsi", "%rdi", "%r8", "%r9", "%r10", "%r11", "memory"

    );


}

void painter::pegarEspecial(uchar * img, uchar * buffer, int c, int f, int w, int h, uchar color)
{
    asm volatile(

        "mov %0, %%rsi ;"       /*dirImg = img*/
        "mov %1, %%rdi ;"       /*dirBuffer = buffer*/
        "movsxd %2, %%r8 ;"     /*C*/
        "movsxd %3, %%r9 ;"     /*F*/
        "movsxd %4, %%rcx ;"    /*W*/
        "movsxd %5, %%rax ;"    /*H*/
        "mov %6, %%dl ;"        /*color*/

        "mov %%r9, %%r10 ;"
        "imul $640, %%r10 ;"
        "add %%r10, %%rsi ;"    /*dirImg = dirImg + f*640*/

        "mov $0, %%r10 ;"       /*cF = 0*/

            "PrimerBuclePegarEspecial: "

                "mov %%r8, %%rbx ;"     /*offC = c*/

                "mov $0, %%r11 ;"       /*cC = 0*/

                    "SegundoBuclePegarEspecial: "

                        "cmpq $640, %%rbx ;"
                        "jae NoCumpleIfPegarEspecial ;"
                        "cmp %%dl, (%%rdi) ;"
                        "je NoCumpleIfPegarEspecial ;"

                        "mov (%%rdi), %%r12b ;"
                        "mov %%r12b, (%%rsi, %%rbx) ;"       /*[dirImg + offC] = [dirBuffer]*/

                        "NoCumpleIfPegarEspecial: "

                        "inc %%rdi ;"                       /*dirBuffer++*/
                        "inc %%rbx ;"                       /*offC++*/

                        "inc %%r11 ;"                       /*cC*/
                        "cmp %%rcx, %%r11 ;"
                        "jb SegundoBuclePegarEspecial ;"

                    "add $640, %%rsi ;"         /*dirImg = dirImg + 640*/

                    "inc %%r10 ;"               /*cF++*/
                    "cmp %%rax, %%r10 ;"
                    "jae FinPegarEspecial ;"
                    "mov %%r9, %%r12 ;"
                    "add %%r10, %%r12 ;"        /*f + cF*/
                    "cmpq $480, %%r12 ;"
                    "jb PrimerBuclePegarEspecial ;"

        "FinPegarEspecial :"
        :
        : "m" (img), "m" (buffer), "m" (c), "m" (f), "m" (w), "m" (h), "m" (color)
        : "%rax","%rbx", "%rcx","%rdx", "%rsi", "%rdi", "%r8", "%r9", "%r10", "%r11", "%r12", "memory"

    );


}




