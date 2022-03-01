/*
	"Drag Racer"
	Autor: Tymoteusz Legiêæ
	Na podstawie https://www.youtube.com/watch?v=rMKHLz3liuk i https://www.youtube.com/watch?v=8Z1VqLd6U34
*/

#include <iostream> //cout, cin
#include <conio.h> //getch
#include <cstdlib> //system
#include <time.h> //srand
using namespace std;

//definicje zmiennych
int y=8, x=5, i=0, j=0, wspXsamochodu=2, wspXopon=(rand()%(x-2)+1), wspYopon, klawisz, wynik=0;
char plansza[8][5];

/*
	y - wysokoœæ planszy
	x - szerokoœæ planszy
	i, j - zmienne do pêtli
	wspXsamochodu - wspó³rzêdna x samochodu
	wspXopon - wspó³rzêdna x opon
	wspYopon - wspó³rzêdna y opon
	klawisz - naciœniêty klawisz
*/

main() {
	
	//konfiguracja generatora liczb za pomoc¹ czasu
	srand(time(NULL));
  
  //wstêpna konfiguracja planszy
  while (i<y) {
    j=0;
    while (j<x) {
    	plansza[i][j]='p';
      j++;
    }
    i++;
  }
  
  /////////////////////////////
  
  //drukowanie ekranu startowego
  i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
	cout << "\n|          |";
	cout << "\n|PRESS PLAY|";
	cout << "\n| TO START |";
	cout << "\n|          |";
	cout << "\n|    db    |";
	cout << "\n|    XX    |";
	cout << "\n|    ^^    |";
	cout << "\n|          |\n";
	i=0;
  while (i<=x) {
    cout << "--";
    i++;
	}
  
  //wstrzymanie a¿ do naciœniêcia dowolnego klawisza
  klawisz=getch();
  
  /////////////////////////////
  
  //g³ówna pêtla gry
  while (!(wspYopon>=y-3&&wspXopon==wspXsamochodu)) {
  	
  	//czyszczenie ekranu
  	system("cls");
    
    //jeœli naciœniêto klawisz
    if (kbhit()) {
    	klawisz=getch(); //weŸ wartoœæ klawisza
    	if (klawisz==224)klawisz+=getch(); //poniewa¿ wartoœæ klawisza mo¿e byæ wiêksza ni¿ 224 getch podaje drug¹ liczbê któr¹ trzeba dodaæ do pierwszej
    
    	//ruch samochodu w prawo/lewo w zale¿noœci od wciœniêtego klawisza (strza³ki i wasd)
			if (klawisz==100||klawisz==301) {
    		wspXsamochodu=wspXsamochodu+1;
  		} else if (klawisz==97||klawisz==299) {
  			wspXsamochodu--;
			}
		}
    
    //zwiêkszanie wyniku przy "z³apaniu" opon oraz generowanie nowej
    if (wspYopon==y) {
			wynik++;
			wspXopon=(rand()%(x-2)+1);
			wspYopon=0;
		}
		
		//blokada ruchu samochodu poza planszê
    if (wspXsamochodu==x-1) { wspXsamochodu=x-2; }
    if (wspXsamochodu==0) { wspXsamochodu=1; }
    
    //przypisywanie odnoœników do ró¿nych czêœci samochodu i opon
    plansza[y-3][wspXsamochodu]='g', plansza[y-2][wspXsamochodu]='y', plansza[y-1][wspXsamochodu]='b';
    plansza[wspYopon][wspXopon]='a', plansza[wspYopon+1][wspXopon]='a';
    
    //drukowanie wyniku
    cout << "  Score: " << wynik;
    
		//drukowanie planszy
    cout << "\n";
    i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
		
		cout << "\n";
    i=0;
    while (i<y) {
    	j=0;
    	cout << "|";
        while (j<x) {
        	switch (plansza[i][j]) {
        		case 'a':
							cout << "OO"; //czêœæ opon
							break;
            case 'p':
							cout << "  "; //puste pole
							break;
						case 'g':
							cout << "db"; //przód samochodu
							break;
						case 'y':
							cout << "XX"; //œrodek samochodu
							break;
						case 'b':
							cout << "^^"; //ty³ samochodu
							break;
        	}
        	j++;
        }
        cout << "|\n";
        i++;
    }
    i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
    
    //czyszczenie pól po samochodu i oponach
    plansza[y-3][wspXsamochodu]='p', plansza[y-2][wspXsamochodu]='p', plansza[y-1][wspXsamochodu]='p';
    plansza[wspYopon][wspXopon]='p';
    
    //ruch opon w dó³
    wspYopon++;
  }
  
  ///////////////////////////////////////
  
  system("cls");
  
  //drukowanie ekranu przegranej
  cout << "  Score: " << wynik << endl;
  i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
	cout << "\n|          |";
	cout << "\n|GAME  OVER|";
	cout << "\n|TRY AGAIN?|";
	cout << "\n|          |";
	cout << "\n|    db    |";
	cout << "\n|    XX    |";
	cout << "\n|    ^^    |";
	cout << "\n|          |\n";
	i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
}
