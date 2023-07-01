;EQUIVALENCIAS USADAS PARA REPRESENTAR LAS POSICIONES DE LA IMPRESION DE CADENAS EN PANTALLA Y LOS COLORES 

;Posiciones en pantalla para imprimir mensajes para el usuario 

INIXMSJ EQU 3
INIYMSJ EQU 23 

;Posiciones en pantalla para pedir al usuario datos de entrada

INIXPEDIR EQU 54
INIYPEDIR EQU 23 

FILLASERARR EQU 2
FILLASERABJ EQU 20
COLLASERIZQ EQU 7
COLLASERDCH EQU 45

;Para escribir en color (fondo frontal) 

COLORRESOLVER EQU 0Bh 
COLORMARCAR EQU 9Bh

;Constantes de tablero y espejos 

NUMCASILLASJUEGO EQU 64
NUMESPEJOSDEBUG EQU 8 
NUMCOLFILJUEGO EQU 8
NUMTIPOSESPEJOS EQU 4   

  ;Caracter de marcado de celda 
   
  CARACTMARCADO EQU '*'

  data segment           
    
  ;Posicion en MatrizJuego
  
  filMatrizJuego DB ?  ;0-7
  colMatrizJuego DB ?  ;0-7
  posMatrizJuego DB ?  ;0-63  

  ;Matriz tablero de juego 
  
  matrizJuego DB 64 dup(0)

  ;Para el numero de espejos del juego, las posiciones que ocupan en el tablero y su tipo
  
  vectorPosEspejos DB 2, 13, 16, 30, 41, 43, 53, 63, 12 dup(0)
  vectorTiposEspejos DB 1, 4, 2, 3, 2, 4, 2, 4, 12 dup(0)
  numEspejos DB 20
  
  ;Para los espejos que el usuario marca como existentes  
  
  vectorPosEspejosMarcados DB 20 dup (-1)
  numEspejosMarcados DB 0

  ;Posicion desde la que se dispara el laser 
  
  posLaser DB ?
  direcDisparoLaser DB ?  ;0:arriba
                          ;1:derecha
                          ;2:abajo
                          ;3:izquierda

  ;Para calcular trayectoria  
    
  posSalidaLaser DB ? 
                        
  cambioTrayTipo1 DB 0, 3, 2, 1
  cambioTrayTipo2 DB 1, 0, 3, 2
  cambioTrayTipo3 DB 2, 1, 0, 3
  cambioTrayTipo4 DB 3, 2, 1, 0   

  ;Para imprimir la la MatrizJuego al resolver 
  
  caractImprimirMatrizJuego DB ' '  ; espacioEnBlanco
                            DB '³'  ; espejoTipo1 
                            DB '/'  ; espejoTipo2
                            DB 'Ä'  ; espejoTipo3 
                            DB '\'  ; espejoTipo4 

  ;Para el PROC colocarCursor  
  
  fila    DB ?
  colum   DB ?

  ;Para la E de texto por parte del usuario
  
  cadenaE DB 7 dup (0)                                                  
                                                     
  tablero DB "F,C         1   2   3   4   5   6   7   8              ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿", 10, 13
          DB "            L1  L2  L3  L4  L5  L6  L7  L8             ³             ³", 10, 13
          DB "          ³   ³   ³   ³   ³   ³   ³   ³   ³            ³  LASER1-32  ³", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ        ³  _          ³", 10, 13
          DB "1  L32    ³   ³   ³   ³   ³   ³   ³   ³   ³    L9      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ", 10, 13
          DB "2  L31    ³   ³   ³   ³   ³   ³   ³   ³   ³    L10     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ        ³             ³", 10, 13
          DB "3  L30    ³   ³   ³   ³   ³   ³   ³   ³   ³    L11     ³MARCAR1-8,1-8³", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ        ³_            ³", 10, 13
          DB "4  L29    ³   ³   ³   ³   ³   ³   ³   ³   ³    L12     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ", 10, 13
          DB "5  L28    ³   ³   ³   ³   ³   ³   ³   ³   ³    L13     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ        ³             ³", 10, 13
          DB "6  L27    ³   ³   ³   ³   ³   ³   ³   ³   ³    L14     ³   RESOLVER  ³", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ        ³   _         ³", 10, 13
          DB "7  L26    ³   ³   ³   ³   ³   ³   ³   ³   ³    L15     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ", 10, 13
          DB "8  L25    ³   ³   ³   ³   ³   ³   ³   ³   ³    L16     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿", 10, 13
          DB "      ÄÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄ        ³             ³", 10, 13
          DB "          ³   ³   ³   ³   ³   ³   ³   ³   ³            ³    SALIR    ³", 10, 13
          DB "           L24 L23 L22 L21 L20 L19 L18 L17             ³    _        ³", 10, 13
          DB "                                                       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ$"

  ;Mensajes de Interfaz 
  
  msjDebug DB "Modo debug (con tablero precargado)? (S/N)$"  
  msjOpcion DB "Introduce Mf,c para marcar R S o Lz para disparar: $" 
  msjPerdida DB "Has perdido la partida$"
  msjGanada DB "Enhorabuena! Has ganado la partida$"   
  
  
;Constantes celda

ALTOCELDA EQU 2
ANCHOCELDA EQU 4
POSPRIMERAFILA EQU 4
POSPRIMERACOLUMNA EQU 12  
   
data ends



stack segment
  DW 128 DUP(0)
stack ends



code segment

;*************************************************************************************                                                                                                                        
;********** Procedimientos utilizados en practicas previas ****************************                                                                                                                        
;*************************************************************************************                                                                                                                        
  
  ;Convierte una cadena de caracteres a un numero entero 
  ;E: DX contiene la direccion de la cadena a convertir (debe apuntar al 1er caracter numerico y terminar en 13 o '$')
  ;S: AX contiene el resultado de la conversion, 0 si hay error o si la cadena a convertir es "0" 
  
  CadenaANumero PROC
    
    push bx
    push cx
    push dx ; cambia con MUL de 16bits
    push si 
    push di
    
    mov si, dx
    xor ax, ax    
    mov bx, 10  
    
    cmp [si], '-'
    jne BCadNum
    
    mov di, si  ;Ajustes si viene un '-' como primer caracter
    inc si

   BCadNum:
    mov cl, [si]          ;Controles de fin
    cmp cl, 13
    je compruebaNeg
    cmp cl, '$'
    je compruebaNeg
    
    cmp cl, '0'
    jl error
    cmp cl, '9'
    jg error
    
    mul bx
    sub cl, '0'
    xor ch, ch
    add ax, cx
    inc si     
    jmp BCadNum
        
   compruebaNeg:   
    cmp [di], '-'
    jne finCadenaANumero
    neg ax
    jmp finCadenaANumero
   
   error:
    xor ax, ax
   
   finCadenaANumero:
    pop di
    pop si
    pop dx
    pop cx
    pop bx
    ret
  CadenaANumero ENDP
  

                                                                                                                        
  ;Convierte un numero entero a una cadena de caracteres terminada en $
  ;E: AX contiene el numero a convertir
  ;   DX contiene la direccion de la cadena donde almacena la cadena resultado
  NumeroACadena PROC 
    push ax
    push bx
    push cx
    push dx
    push di
    
    mov bx, 10
    mov di, dx
    
    xor cx, cx

    cmp ax, 0  
    jge BNumCad

    mov [di], '-'
    inc di 
    neg ax
    
   BNumCad:        ;Bucle que transforma cada digito a caracter, de menor a mayor peso     
    xor dx, dx
    div bx
    add dl, '0'
    push dx 
    inc cx
    cmp ax, 0
    jne BNumCad

   BInvertir:      ;Bucle para invertir los restos    
    pop [di]
    inc di
    loop BInvertir

    mov [di], '$'

    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    ret
  NumeroACadena ENDP

 
 
  ;F: Imprime una cadena terminada en $ en la posicion donde se encuentre el cursor 
  ;E: DX direccion de comienzo de la cadena a imprimir
      
  Imprimir PROC 
    
    push ax

    mov ah,9h
    int 21h

    pop ax 
    
    ret 
    
  Imprimir ENDP 

 
 
  ;F: Imprime un caracter a color en la posicion actual del cursor
  ;E: AL contiene el caracter
  ;   BL el codigo de color a imprimir 
  
  ImprimirCarColor PROC 
    
    push ax
    push bx
    push cx

    mov ah, 9
    xor bh, bh
    mov cx, 1
    int 10h

    pop cx
    pop bx
    pop ax
    
    ret 
    
  ImprimirCarColor ENDP
 
 

  ;F: Coloca el cursor en una determinada fila y colum de pantalla
  ;E: las variables fila y colum deben contener los valores de posicionamiento 
  
  ColocarCursor PROC
    
    push ax
    push bx
    push dx

    mov ah, 2
    mov dh, fila
    mov dl, colum
    xor bh, bh
    int 10h

    pop dx
    pop bx
    pop ax 
    
    ret 
            
  ColocarCursor ENDP                                                                                                   

   
   
  ;Lee una cadena por teclado
  ;E: DX contiene la direccion de la cadena donde se almacenar  la cadena leida                        
  ;E: la posicion 0 de esa cadena debe contener el numero maximo de caracteres a leer 
  
  LeerCadena PROC 
    
    push ax

    mov ah, 0ah
    int 21h

    pop ax 
    
    ret  
    
  LeerCadena ENDP
  
  
;**************************************************************************************
;************************** Nuevos procedimientos que se entregan ***************************
;**************************************************************************************

  ;F: Calcula un valor aleatorio entre 0 y un valor maximo dado-1
  ;E: BL valor maximo 
  ;S: AH valor aleatorio calculado 
  
  NumAleatorio PROC 
    
    push cx
    push dx

    mov ah,2Ch ;interrupcion que recupera la hora actual del sistema operativo
    int 21h
    ;ch=horas cl=minutos dh=segundos dl=centesimas de segundo, 1/100 secs

    xor ah,ah
    mov al,dl  
    div bl
    
    pop dx
    pop cx 
    
    ret  
    
  NumAleatorio ENDP 
               
               
  
  ;F: Lee un caracter por teclado sin eco por pantalla
  ;S: AL caracter ASCII leido 
  
  LeerTeclaSinEco PROC   
    
    mov ah,8 ;1 para que sea con eco
    int 21h 

    ret     
    
  LeerTeclaSinEco ENDP   
  
  

  ;F: Oculta el cursor del teclado 
  
  OcultarCursor PROC
    
    push ax
    push cx

    mov ah,1
    mov ch,20h
    xor cl,cl
    int 10h

    pop cx
    pop ax 
    
    ret
    
  OcultarCursor ENDP
  
               
               
  ;F: Muestra el cusor del teclado
  
  MostrarCursor PROC  
    
    push ax
    push cx

    mov ah,1
    mov ch,0Bh
    mov cl,0Ch
    int 10h

    pop cx
    pop ax 
        
    ret 
    
  MostrarCursor ENDP       
  


  ;F: Borra la pantalla (la deja en negro)  
  
  BorrarPantalla PROC 
    
    push ax
    push bx
    push cx
    push dx

    mov ah, 6h
    xor al, al
    mov bh, 7
    xor cx, cx
    mov dh, 24
    mov dl, 79
    int 10h 

    pop dx
    pop cx
    pop bx
    pop ax
    
    ret 
    
  BorrarPantalla ENDP

              
  ;F: Borra la linea de mensajes completa 
             
  BorrarLineaMsj PROC
      
    push ax
    push bx
    push cx
    push dx

    mov ah, 6h
    xor al, al
    mov bh, 7
    xor cl, cl
    mov ch, INIYMSJ 
    mov dh, INIYMSJ+1
    mov dl, 79
    int 10h 

    pop dx
    pop cx
    pop bx
    pop ax 
    
    ret    
    
  BorrarLineaMsj ENDP    
              
              
  
  ;F: Borra la zona de las cadenas de mensajes que imprimen en pantalla
  
  BorrarEntradaUsuario PROC  
    
    push ax
    push bx
    push cx
    push dx

    mov ah, 6h
    xor al, al
    mov bh, 7
    mov cl, INIXPEDIR
    mov ch, INIYMSJ 
    mov dh, INIYMSJ+1
    mov dl, INIXPEDIR+4
    int 10h 

    pop dx
    pop cx
    pop bx
    pop ax 
    
    ret  
    
  BorrarEntradaUsuario ENDP    
  
  
  
;F: Limpia el buffer de entrada del teclado por si tuviera algo 
  
  LimpiarBufferTeclado PROC
    
    push ax

    mov ax,0C00h
    int 21h

    pop ax
    
    ret
    
  LimpiarBufferTeclado ENDP               
             

;**************************************************************************************
;******************** Procedimientos de IU ********************************************
;**************************************************************************************

;F: Marca una celda seleccionada por el usuario (determinada por filMatrizJuego y colMatrizJuego), 
;   en la que se piensa que contiene un espejo. No se marca si:
;   ya se han marcado todos los espejos o la celda ya esta marcada

  MarcarEspejo PROC
  
    push ax
    push bx 
    push cx
    push si
              
    xor ch,ch
    
    mov ah,numEspejosMarcados
    cmp ah,numEspejos 
    je FinMarcarEspejo  
    
    dec filMatrizJuego 
    dec colMatrizJuego 
    
    call MatrizAVector
    mov al,posMatrizJuego
    lea si,vectorPosEspejosMarcados
    mov cl,numEspejosMarcados
                       
    call BuscarElemVector
    
    cmp bl,1                    
    je FinMarcarEspejo
    
    inc numEspejosMarcados
    mov cl,numEspejosMarcados
    call InsertarVect 
    
    call MatrizAPantalla
    call ColocarCursor
    
    mov al,CARACTMARCADO
    mov bl,COLORMARCAR  
    call ImprimirCarColor
                        
   FinMarcarEspejo:
    
    pop si
    pop cx
    pop bx    
    pop ax
  
    ret
  
  MarcarEspejo ENDP 
  
;F: En base a los valores de filMatrizJuego y colMatrizJuego devuelve los 
;   valores en las variables fila y colum para marcar el espejo correctamente  
;   en pantalla 
;   fila=filMatrizJuego*ALTOCELDA + POSPRIMERAFILA
;   colum = colMatrizJuego * ANCHOCELDA + POSPRIMERACOLUMNA
   
  MatrizAPantalla PROC 
     
    push ax
    push bx
     
    xor ah,ah
    
    mov al,filMatrizJuego
    mov bl,ALTOCELDA
    mul bl
    add al,POSPRIMERAFILA
    mov fila,al
    
    mov al,colMatrizJuego 
    mov bl,ANCHOCELDA
    mul bl
    add al,POSPRIMERACOLUMNA 
    mov colum,al
    
    pop bx
    pop ax
      
    ret
    
  MatrizAPantalla ENDP 
   
;F: Calcula la direccion (direcDisparoLaser) y la posicoion de disparo (filMatrizJuego y colMAtrizJuego) a partir de posLaser
;   PosLaser entre 1 y 8: direcDisparoLaser = 2 (abajo), filMatrizJuego = 0, colMatrizJuego=posLaser - 1
;   PosLaser entre 9 y 16: direcDisparoLaser = 3 (izqierda), filMatrizJuego=posLaser-9, colMatrizJuego = 7
;   PosLaser entre 17 y 24: direcDisparoLaser = 0 (arriba), filMatrizJuego=7, colMatrizJuego = 24-posLaser
;   PosLaser entre 25 y 32: direcDisparoLaser = 1 (drecha), filMatrizJuego = 32-PosLaser, colMatrizJuego=0
;   Tambien recorre la matriz moviendo el laser segun corresponda y comprueba si se encuentra dentro del tablero 
 
  DispararLaser PROC
    
    push ax
    push bx
    push dx
    
    cmp posLaser,8
    jle Abajo
    
    cmp posLaser,16
    jle Izquierda
    
    cmp posLaser,24
    jle Arriba

  ;Derecha

    mov direcDisparoLaser,1
    mov al,32
    sub al,posLaser
    mov filMatrizJuego,al
    mov colMAtrizJuego,0
    
    jmp ComprobarEspejo  

   Abajo:
    
    mov direcDisparoLaser,2
    mov filMatrizJuego,0
    mov al,posLaser
    dec al
    mov colMatrizJuego,al
    
    jmp ComprobarEspejo
    
   Izquierda: 
   
    mov direcDisparoLaser,3
    mov al,posLaser   
    sub al,9
    mov filMatrizJuego,al 
    mov colMatrizJuego,7
    
    jmp ComprobarEspejo
    
   Arriba:
   
    mov direcDisparoLaser,0 
    mov filMatrizJuego,7 
    mov al,24
    sub al,posLaser
    mov colMatrizJuego,al
    
         
    
   ComprobarEspejo: 
   
    xor bh,bh 
    
    call MatrizAVector
    mov bl,posMatrizJuego              
    mov bl, MatrizJuego[bx] 
    
    cmp bl,0
    je Mover
    
    cmp bl,2
    je TipoDos
    
    cmp bl,3
    je tipoTres
    
    cmp bl,4
    je TipoCuatro 
    
  ;TipoUno
     
    mov bl,direcDisparoLaser
    mov al,cambioTrayTipo1[bx]
    mov direcDisparoLaser,al
     
    jmp Mover
    
   TipoDos:
   
    mov bl,direcDisparoLaser
    mov al,cambioTrayTipo2[bx]
    mov direcDisparoLaser,al
    
    jmp Mover
    
   TipoTres:
   
    mov bl,direcDisparoLaser
    mov al,cambioTrayTipo3[bx]
    mov direcDisparoLaser,al 
    
    jmp Mover
   
   TipoCuatro:
   
    mov bl,direcDisparoLaser
    mov al,cambioTrayTipo4[bx]
    mov direcDisparoLaser,al 
     
   Mover:
    
    cmp direcDisparoLaser,0
    je Subir
    
    cmp direcDisparoLaser,1
    je Derecha   
     
    cmp direcDisparoLaser,2
    je Bajar
    
  ;Izquierda
  
    dec colMatrizJuego
    jmp ComprobarTablero 
    
   Subir:
   
    dec filMatrizJuego
    jmp ComprobarTablero
    
   Bajar:
   
    inc filMatrizJuego
    jmp ComprobarTablero
    
   Derecha:
   
    inc colMatrizJuego
    
   ComprobarTablero:         
    
    cmp filMatrizJuego,0
    jl FueraTablero
    
    cmp filMatrizJuego,7
    jg FueraTablero
    
    cmp colMatrizJuego,0 
    jl FueraTablero
    
    cmp colMatrizJuego,7
    jg FueraTablero
    
    jmp ComprobarEspejo
    
   FueraTablero:
     
    call MatrizAPantalla
    
    xor ah,ah 
    
    mov al,posLaser
    lea dx,posLaser  
    call NumeroACadena
    
    call ColocarCursor
    call Imprimir 
     
    pop dx
    pop bx
    pop ax
    
    ret
    
  DispararLaser ENDP
  
;F: Comprueba si las primeras N posiciones de 2 vectores contienen los mismos valores. 
;   Tambien imprime en color cada espejo
;S: Mensaje de victoria o derrota segun si se ha conseguido lograr el objetivo del juego
;   Espejos pintados en pantalla  
  
  ResolverPartida PROC
    
    push ax
    push bx
    push cx
    push dx
    push di
    push si
   
    call BorrarLineaMsj
    
    xor di,di
    xor ah,ah
    xor bh,bh
    xor dh,dh
             
   ImprimirEspejo:
   
;Sacamos la posicion del espejo y la actualizamos al tablero de la pantalla   
   
    mov al,vectorPosEspejos[di]
    mov posMatrizJuego, al
    call vectorAMatriz
    
    call MatrizAPantalla
    call ColocarCursor 
    
;Sacamos el tipo de espejo y lo imprimimos 
    
    mov si,ax 
    mov bl,MatrizJuego[si] 
    
    mov al,caractImprimirMatrizJuego[bx]
    mov bl,COLORRESOLVER
    call ImprimirCarColor
   
    inc di
    
    mov dl,numEspejos
    
    cmp di,dx
    jl ImprimirEspejo
    
;Vemos si hemos ganado o perdido

    mov ah,numEspejosMarcados
    cmp ah,numEspejos
    jne HasPerdido 
    
    xor ch,ch
    xor di,di
    
   InicioComprobacion:
    
    mov al,vectorPosEspejosMarcados[di]
    lea si,vectorPosEspejos
    mov cl,numEspejos
    
    call BuscarElemVector
    
    cmp bl,0
    je HasPerdido
    
    inc di
    mov bx,di
    cmp numEspejosMarcados,bl
    jne InicioComprobacion
    
;HasGanado

    mov fila,INIYMSJ
    mov colum,INIXMSJ  
    call ColocarCursor 
    
    lea dx,msjGanada
    call Imprimir  
    jmp FinResolverPartida
    
   HasPerdido:
       
    mov fila,INIYMSJ
    mov colum,INIXMSJ  
    call ColocarCursor 
    
    lea dx,msjPerdida
    call Imprimir     
    
   FinResolverPartida: 
    
    pop si
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    
    ret
    
  ResolverPartida ENDP  


;**************************************************************************************
;******************** Procedimientos para la logica del juego *************************
;************************************************************************************** 

 ;****************************************  
;*************** SESION 6 ***************                
;**************************************** 

;F: Dados los parametros filMatrizJuego y colMatrizJuego calcula la posMatrizJuego de tal manera que
;   posMatrizJuego = filMatrizJuego*NUMCOLFILJUEGO + colMatrizJuego
;E: filMatrizJuego contiene la fila introducida por el usuario
;   colMatrizJuego contiene la columna introducida por el usuario
;S: posMatrizJuego contiene la posicion de la matriz correspondiente
 
  MatrizAVector PROC
     
    push ax
    push bx
           
    xor ah, ah
           
    mov al, filMatrizJuego 
    mov bl, NUMCOLFILJUEGO
    mul bl
    add al, colMatrizJuego
    mov posMatrizJuego,al 
    
    pop bx
    pop ax
    
    ret 
       
  MatrizAVector ENDP 
  
;F: Dados el parametro posMatrizJuego calcula la fila y columna correspondiente de la forma
;  filMatrizJuego = posMatrizJuego/NUMCOLFILJUEGO  
;  colMatrizJuego = posMatrizJuego%NUMCOLFILJUEGO
;E: posMatrizJuego contiene la posicion de la matriz introducida por el usuario   
;S: colMatrizJuego contiene la posicion de la columna correspondiente
;   filMatrizJuego contiene la fila correspondiente
  
  VectorAMatriz PROC
  
    push ax
    push dx
   
    xor ah, ah
  
    mov al,posMatrizJuego
    mov dl,NUMCOLFILJUEGO 
    div dl
    mov colMatrizJuego,ah
    mov filMatrizJuego, al 
      
    pop dx
    pop ax  
   
    ret
  
  VectorAMatriz ENDP  
  
;****************************************  
;*************** SESION 7 ***************                
;**************************************** 

;F: Insertar en la primera posicion vacia de un vector un elemento.
;E: AL contiene el numero a introducir
;   SI la direccion del 1er elemento del vector   
;   CX tamano del vector
;S: la variable apuntada por SI 
    
  InsertarVect PROC
        
    push cx
    push si  
          
   BucleIns:
              
    cmp [si],-1
    je insertar 
    inc si     
    loop BucleIns
      
    jmp FinalInsertarVect
 
   Insertar:
      
    mov [si], al
     
   FinalInsertarVect:
      
    pop si
    pop cx
       
    ret   
      
  InsertarVect ENDP 
 
;F: Busca un numero dado en el vector, si lo encuentra devuelve 1, si no, un 0
;E: AL contiene el numero a buscar
;   SI la direccion del 1er elemento del vector
;   CX tamano del vector
;S: BL devuelve 0 si no lo encuentra o 1 en caso contrario
    
  BuscarElemVector PROC
        
    push si
    push cx
           
   BucleBusqueda: 
       
    cmp cx,0
    je FinalBuscarElemVector    
       
    cmp [si],al
    je Encontrado
    inc si
    loop BucleBusqueda 
        
    mov bl,0
    jmp FinalBuscarElemVector
        
   Encontrado: 
  
    mov bl,1
       
   FinalBuscarElemVector:    
           
    pop cx
    pop si
        
    ret  
       
  BuscarElemVector ENDP  
  
;F: Rellena un vector de numeros aleatorios 
;E: SI contiene la direccion del vector en el que queremos insertar los numeros aleatorios
;   AH el valor a insertar
;   BL el valor maximo
;   CX el numero de elementos aleatorios a generar y almacenar en el vector
;S: Se modifica vRandom
  
  RellenarRandom PROC 
        
    push si
    push cx
    push ax
          
    cmp cx,0
    je FinalRellenarRandom 
     
   BucleInsercion: 
         
    call NumAleatorio
    inc ah
    mov [si], ah
    inc si
    loop BucleInsercion  
      
   FinalRellenarRandom:
        
    pop ax
    pop cx
    pop si
    
    ret 
   
  RellenarRandom ENDP 
  
;****************************************  
;*************** SESION 8 ***************                
;****************************************  

;F: Comprueba si la cadena indicada contiene una L seguida de valor numerico entre 1 y 32,
;   una letra M seguida de dos numeros f y c, una letra R o una letra S
;E: SI contiene la direccion de la cadena donde se encuentran los caracteres indicados
;S: BL sera 1  en caso de tratarse de la letra L seguida de un numero entre 1 y 32. 
;   BL sera 2 en caso de ser la letra M seguida de f,c.
;   BL sera 3 en caso de ser la letra R.
;   BL sera 4 en caso de ser la letra S.
;   BL sera 0 en cualquier otro caso.
  
  ValidarEntradaOpcion PROC   
    
    push ax 
    push dx
    
    xor bl,bl
    
    cmp [si][2],'L'
    je EsL
    
    cmp [si][2],'M'
    je EsM
    
    cmp [si][2],'R'
    je EsR
    
    cmp [si][2],'S'
    je EsS 
           
    jmp FinalValidarEntradaOpcion
           
   EsL:
     
    lea dx,cadenaE[3]
    call CadenaANumero 
     
    cmp al,1
    jl FinalValidarEntradaOpcion 
    cmp al,32
    jg FinalValidarEntradaOpcion 
     
    mov bl,1 
    mov posLaser,al
    jmp FinalValidarEntradaOpcion
     
   EsM:
     
    cmp cadenaE[4],','
    jne FinalValidarEntradaOpcion
    mov cadenaE[4], 13
                 
    lea dx,cadenaE[3]                         
    call CadenaANumero 
      
    cmp al,1
    jl FinalValidarEntradaOpcion
    cmp al,8
    jg FinalValidarEntradaOpcion

    mov filMatrizJuego,al
      
    lea dx,cadenaE[5]
    call CadenaANumero
     
    cmp al,1
    jl FinalValidarEntradaOpcion
    cmp al,8
    jg FinalValidarEntradaOpcion
     
    mov colMatrizJuego,al
      
    mov bl,2
    jmp FinalValidarEntradaOpcion
      
   EsR:
     
    mov bl,3
    jmp FinalValidarEntradaOpcion
      
   EsS:
     
    mov bl,4
         
   FinalValidarEntradaOpcion:
     
    pop dx
    pop ax
    
    ret
    
  ValidarEntradaOpcion ENDP 
  
;****************************************  
;*************** SESION 9 ***************                
;****************************************  
  
;F: Actualiza un vector introduciendo en dicho vector,
;   en las posiciones que indica un vector de posiciones,
;   los datos que vienen dados en un tercer vector
;E: En SI se guarda la direccion de comienzo del vector a rellenar
;   En BX se guarda la direccion de inicio vector que indica las posiciones a rellenar
;   En DI se guarda la direccion de inicio del vector que tiene los datos que se van a usar para rellenar
;   En CX se guarda el tamano del vector de posiciones y del vector de contenidos
;S:Vector posiciones con valores numericos 
  
  RellenarVector PROC 
    
    push ax
    push bx
    push cx
    push si
    push di 
                     
   Rellenar:
     
    xor ah, ah 
    mov al, [bx] 
      
    push bx 
    
    
    mov bx, ax          ; contenido de vector2 en bx
                                        
    mov al, [di]        ; valor a asignar
    
    mov [si+bx], al     ; asignacion 
    
    pop bx
    inc bx
    inc di  
          
    loop Rellenar 
    
    pop di
    pop si
    pop cx
    pop bx
    pop ax 
                     
    ret
                     
  RellenarVector ENDP 
  
;F: Invoca al procedimiento "Rellenar Vector" fijando como parametros un primer vector
;   de 64 elementos de tipo byte iniciados a 0 en el segmento de datos con el nombre
;   "MatrizJuego", un segundo vector inicializado con NUMESPEJOSDEBUG (8) valores 
;   distintos entre si, entre 0 y 63 que son las posiciones del vector MatrizJuego
;   que se rellenaran, un tercer vector con NUMESPEJOSDEBUG (8)
;   valores entre 1 y 4 que son los tipos de espejos con los que se rellenaran las posiciones. 
  
  InicializarMatrizJuegoDebug PROC  
    
    push si
    push bx
    push di
    push cx
    push ax
    
    lea si,matrizJuego        ;vector a rellenar
    lea bx,vectorPosEspejos   ;vector de posiciones
    lea di,vectorTiposEspejos ;vector de tipos de espejos
   
    xor ch,ch
       
    mov al,NUMESPEJOSDEBUG 
    mov numEspejos,al
    mov cl,numEspejos 
    
    call RellenarVector 
   
    pop ax
    pop cx
    pop di
    pop bx
    pop si
    
    ret
  
  InicializarMatrizJuegoDebug ENDP
  
;****************************************  
;*************** Resto ******************                
;****************************************  

;F: Relena el vector vectorPosEspejos de numeros aleatorios sin repetir 

  RellenarVectorRandomSinRepetir PROC
    
    push ax
    push bx
    push cx
    push di
    push si
           
    xor ch,ch
    xor di,di
           
   InicioNumRandom:
   
    mov bl,NUMCASILLASJUEGO 
    call NumAleatorio
    
    mov al,ah
    lea si,vectorPosEspejos
    mov cl,numEspejos 
    
    call BuscarElemVector 
    
    cmp bl,0
    je InsertarNumRandomSinRepe
    
    jmp InicioNumRandom
    
       
   InsertarNumRandomSinRepe:
   
    mov vectorPosEspejos[di],al  
    inc di
    
    cmp di,cx
    jl InicioNumRandom
    
    pop si
    pop di
    pop cx
    pop bx
    pop ax
    
    ret 
    
  RellenarVectorRandomSinRepetir ENDP  
    

;F: Rellenar vectorTiposEspejos con 20 valores aleatorios (tipos de espejos, entre 1 y 4) 
;   y vectorPosEspejos con 20 valores aleatorios distintos entre si (posiciones entre 0 y 63)
;   Usandor el procedimiento RellenarVector de la sesion 9 para rellenar la variable matrizJuego
;   La variable numEspejos se fija con el valor 20 
  
  InicializarMatrizJuegoRandom PROC
    
    push bx
    push cx
    push di
    push si
    
    call RellenarVectorRandomSinRepetir
     
    xor ch,ch 
     
    lea si,vectorTiposEspejos
    mov cl,numEspejos
    mov bl,4
    
    call RellenarRandom
    
    lea si,matrizJuego
    lea bx,vectorPosEspejos
    lea di,vectorTiposEspejos
    mov cl,numEspejos
    
    call RellenarVector
    
    pop si
    pop di
    pop cx
    pop bx  
    
    ret
    
  InicializarMatrizJuegoRandom ENDP
  
;*************************************************************************************
;************************** Programa Principal ***************************************
;*************************************************************************************


   start:      

    mov ax, data
    mov ds, ax 
    
;Imprimir tablero
    
    lea dx, tablero
    call imprimir   
    
;Eleccion de modo  
    
    mov fila,INIYMSJ
    mov colum,INIXMSJ  
    call ColocarCursor 
    
    lea dx, msjDebug
    call Imprimir
    
    call OcultarCursor
    
   PedirTeclaDeNuevo:
      
    call LeerTeclaSinEco
   
    cmp al,'S'
    je ModoDebug
    
    cmp al,'N'
    je ModoRandom
    
    jmp PedirTeclaDeNuevo
    
;Modo Debug    
    
   ModoDebug: 
   
    call InicializarMatrizJuegoDebug  
    
    call BorrarLineaMsj
   
    call ColocarCursor
    lea dx, msjOpcion  
    call Imprimir  
   
    call MostrarCursor
    
   PedirOpcionDeNuevo:
    
    mov fila,INIYPEDIR
    mov colum,INIXPEDIR
    call ColocarCursor       
  
    call BorrarEntradaUsuario
     
    mov CadenaE[0],5 
    lea dx,cadenaE
    call LeerCadena 
    
    lea si,cadenaE
    call ValidarEntradaOpcion  
   
    cmp bl,0
    je PedirOpcionDeNuevo
    
    cmp bl,1
    je Laser
    
    cmp bl,2
    je Marcar
    
    cmp bl,3 
    je Resolver
    
    cmp bl,4
    je FinJuego
    
   Laser:
    
    call DispararLaser
    jmp PedirOpcionDeNuevo
    
   Marcar:
   
    call MarcarEspejo
    jmp PedirOpcionDeNuevo   
        
   Resolver:
   
    call ResolverPartida 
    jmp FinJuego
    
             
;Modo Aleatorio   
    
   ModoRandom:
  
    call InicializarMatrizJuegoRandom  
    
    call BorrarLineaMsj
   
    call ColocarCursor
    lea dx, msjOpcion  
    call Imprimir  
   
    call MostrarCursor 
    
    jmp PedirOpcionDeNuevo
  
  
;Final del Programa

   FinJuego:
    
    mov ah, 4ch
    int 21h
    
    code ends  

  END Start
