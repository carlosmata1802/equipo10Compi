int main(int argc, char **argv )
{
int tok = 0;

   ++argv, --argc;  /* se salta el nombre del programa */
   if ( argc > 0 )
      yyin = fopen( argv[0], "r" );
   else
      yyin = stdin;

while((tok = yylex())){
   switch(tok){
     case ENTERO:
        printf( "Un entero: %d\n", u.i); break;
     case REAL:
        printf( "Un real  : %g.2\n",u.f); break;
     case STRING:
        printf("Una cadena : %s\n",u.s ); break;
     case SI:
     case PARA:
     case DESPLIEGA:
     case FUNCTION:
        printf("Una palabra clave: %s\n",yytext ); break;
     case ID:
        printf( "Un identificador: %s\n",u.s); break;
     case '+':
     case '-':
     case '*':
     case '/':
        printf( "Un operador: %s\n", yytext ); break;
   }
 }
   return 1;
}
