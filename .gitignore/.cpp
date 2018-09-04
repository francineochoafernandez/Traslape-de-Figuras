#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

struct Figura
{
  float rala;//Radio o lado
  float la2;//Lado 2 para el caso del rectangulo
  int xc, yc;
  int Cuadrante()
  {
    if(xc>=0 && yc>=0)
    {
      return 1;
    }
    else if(xc<0 && yc>=0)
    {
      return 2;
    }
    else if(xc<0 && yc<0)
    {
      return 3;
    }
    else
    {
      return 4;
    }
  }

};

void PideDatos(struct Figura *figura, char o)//Función que pide datos e imprime cuadrante
{
  if(o=='c' || o=='e' || o=='f')
  {
    cout << "Dame el lado menor del rectangulo: " << '\n';
    cin >> figura->rala;
    cout << "Dame el lado mayor del rectangulo: " << '\n';
    cin >> figura->la2;
  }
  else
  {
    cout << "Dame el radio o lado: " << '\n';
    cin >> figura->rala;
  }
  cout << "Indica la coordenada x del centro: " << '\n';
  cin >> figura->xc;
  cout << "Indica la coordenada y del centro: " << '\n';
  cin >> figura->yc;
  cout << "Esta en el cuadrante: " <<figura->Cuadrante()<< '\n'<< '\n';
}

void EncimadosCirc(struct Figura figura1, struct Figura figura2)
{
  float dmin=figura1.rala + figura2.rala;
  float dpun=sqrt( pow(figura2.xc-figura1.xc,2) + pow(figura2.yc-figura1.yc,2) );
  if(dmin>dpun)
  {
    cout << "SI se traslapan los círculos!! "<< '\n';
  }
  else
  {
    cout << "NO se traslapan los círculos!! "<< '\n';
  }
}

void EncimadosCuad(struct Figura figura1, struct Figura figura2)
{
  float dmin=(figura1.rala + figura2.rala)/2;
  float dmin2=(figura1.rala + figura2.rala)/sqrt(2);
  float dpun=sqrt( pow(figura2.xc-figura1.xc,2) + pow(figura2.yc-figura1.yc,2) );

  if(dmin2<dpun)
  {
    if(dmin<dpun)
    {
      cout << "NO se traslapan los cuadrados!! "<< '\n';
    }
  }
  else
  {
    cout << "SI se traslapan los cuadrados!! "<< '\n';
  }

}

void EncimadosRect(struct Figura figura1, struct Figura figura2)
{
  float dmin1=(figura1.rala + figura2.rala)/2;//lado chico
  float dmin2=(figura1.la2 + figura2.la2)/2;//lado grande
  float dmin3= sqrt(pow(figura1.la2/2,2)+pow(figura1.rala/2,2)) + sqrt(pow(figura2.la2/2,2)+pow(figura2.rala/2,2));
  float dpun=sqrt( pow(figura2.xc-figura1.xc,2) + pow(figura2.yc-figura1.yc,2) );

  if(dmin3<dpun)
  {
    if(dmin2<dpun)
    {
      if(dmin1<dpun)
      {
          cout << "NO se traslapan los cuadrados!! "<< '\n';
      }

    }
  }
  else
  {
    cout << "SI se traslapan los cuadrados!! "<< '\n';
  }

}

void EncimadosCircCuad(struct Figura figura1, struct Figura figura2)
{
  float dmin1=figura1.rala + (figura2.rala)/2;//distancia mas chica
  float dmin2=figura1.rala + (figura2.rala)/sqrt(2);//distancia mas grande
  float dpun=sqrt( pow(figura2.xc-figura1.xc,2) + pow(figura2.yc-figura1.yc,2) );
  if(dmin2<dpun)
  {
    if(dmin1<dpun)
    {
      cout << "NO se traslapan los cuadrados!! "<< '\n';
    }
  }
  else
  {
    cout << "SI se traslapan los cuadrados!! "<< '\n';
  }
}

void EncimadosCircRect(struct Figura figura1, struct Figura figura2)
{
  float dmin1=figura1.rala + (figura2.rala)/2;//lado chico
  float dmin2=figura1.rala + (figura2.la2)/2;//lado grande
  float dmin3= figura1.rala + sqrt(pow(figura2.la2/2,2)+pow(figura2.rala/2,2));//lado mas grande
  float dpun=sqrt( pow(figura2.xc-figura1.xc,2) + pow(figura2.yc-figura1.yc,2) );

  if(dmin3<dpun)
  {
    if(dmin2<dpun)
    {
      if(dmin1<dpun)
      {
          cout << "NO se traslapan los cuadrados!! "<< '\n';
      }

    }
  }
  else
  {
    cout << "SI se traslapan los cuadrados!! "<< '\n';
  }

}

void EncimadosCuadRect(struct Figura figura1, struct Figura figura2)
{
  float dmin1=(figura1.rala + figura2.rala)/2;//lado chico del rec con lado a la mitad del cuad
  float dmin2=(figura1.rala + figura2.la2)/2;//lado grande del rec con lado a la mitad del cuad
  float dmin3=(figura1.rala)/sqrt(2) + figura2.rala/2;//lado chico del rec con lado a la mitad de la hipotenusa del cuad
  float dmin4=(figura1.rala)/sqrt(2) + figura2.la2/2;//lado grande del rec con lado a la mitad de la hipotenusa del cuad
  float dmin5= figura1.rala/2 + sqrt(pow(figura2.la2/2,2)+pow(figura2.rala/2,2));
  float dmin6= (figura1.rala)/sqrt(2) + sqrt(pow(figura2.la2/2,2)+pow(figura2.rala/2,2));
  float dpun=sqrt( pow(figura2.xc-figura1.xc,2) + pow(figura2.yc-figura1.yc,2) );

  if(dmin6<dpun)
  {
    if(dmin5<dpun)
    {
      if(dmin4<dpun)
      {
        if(dmin3<dpun)
        {
          if(dmin2<dpun)
          {
            if(dmin1<dpun)
            {
              cout << "NO se traslapan los cuadrados!! "<< '\n';
            }
          }
        }
      }
    }
  }
  else
  {
    cout << "SI se traslapan los cuadrados!! "<< '\n';
  }

}

int main (void)
{
  char o;
  printf("\nHola este programa checa si dos figuras se traslapan.\n");
  printf("Dame la opción que desees ejecutar:\n");
  printf("\na)Comparación entre dos circulos.\nb)Comparación entre dos cuadrados.\nc)Comparación entre dos rectangulos.\nd)Comparación entre circulo y cuadrado.\ne)Comparación entre círculo y rectángulo.\nf)Comparación entre cuadrado y rectángulo.\n");
  scanf("%c",&o);
  switch (o)
	{
	 case 'a':
        struct Figura circ1;
        printf("\nPara el 1er círculo:\n");
        PideDatos(&circ1,o);
        struct Figura circ2;
        printf("\nPara el 2do círculo:\n");
        PideDatos(&circ2,o);
        EncimadosCirc(circ1, circ2);
        break;
    case 'b':
        struct Figura cuad1;
        printf("\nPara el 1er cuadrado:\n");
        PideDatos(&cuad1,o);
        struct Figura cuad2;
        printf("\nPara el 2do cuadrado:\n");
        PideDatos(&cuad2,o);
        EncimadosCuad(cuad1, cuad2);
        break;
    case 'c':
        struct Figura rect1;
        printf("\nPara el 1er rectangulo:\n");
        PideDatos(&rect1,o);
        struct Figura rect2;
        printf("\nPara el 2do rectangulo:\n");
        PideDatos(&rect2,o);
        EncimadosRect(rect1, rect2);
        break;
     case 'd':
        struct Figura circ3;
        printf("\nPara el círculo:\n");
        PideDatos(&circ3,o);
        struct Figura cuad3;
        printf("\nPara el cuadrado:\n");
        PideDatos(&cuad3,o);
        EncimadosCircCuad(circ3, cuad3);
        break;
      case 'e':
        struct Figura circ4;
        printf("\nPara el círculo:\n");
        PideDatos(&circ4,'a');
        struct Figura rect3;
        printf("\nPara el rectangulo:\n");
        PideDatos(&rect3,o);
        EncimadosCircRect(circ4, rect3);
        break;
      case 'f':
        struct Figura cuad4;
        printf("\nPara el cuadrado:\n");
        PideDatos(&cuad4,'a');
        struct Figura rect4;
        printf("\nPara el rectangulo:\n");
        PideDatos(&rect4,o);
        EncimadosCuadRect(cuad4, rect4);
        break;
    default:
        printf("Letra no asociada a operación.\n");
        break;

    }

  return 0;
}
