#include <iostream>
#include <string>
using namespace std;


#define NUM 0
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define EQU 5
#define OPP 6
#define CLP 7
#define COM 8
#define CAN 9
#define SPA 10
#define ERROR -1

/*
 * Error ->ERROR message
 *
 * >>>2*4*3=
 * ;24
 * >>>-+*24
 * ERROR;0
 * >>>24/0=
 * ERROR;0
 * >>>*23
 * :0		<-answer of 0*23
 *
 *
 * En route for Execution -> apply ":" to the forward
 * Answer -> apply ";" to the forward
 * >>>2*4*3
 * :24
 * >>>-10
 * :14
 * >>>*(32-33/3)=
 * ;294
 * >>>24*3	<-ignore the before result
 * :72
 * >>>;24*5	<-ignore the before result. You can use ";" to emphasize ignoring
 * :120
 *
*/


class Calculator{
    public:
    string answer;
    Calculator(){
	answer=";";
    }
    int wILetter(char x){
	int a;
	switch(x){
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	    case '8':
	    case '9':
		a=NUM;
		break;
	    case '+':a=ADD;break;
	    case '-':a=SUB;break;
	    case '*':a=MUL;break;
	    case '/':a=DIV;break;
	    case '=':a=EQU;break;
	    case '(':a=OPP;break;
	    case ')':a=CLP;break;
	    case '.':a=COM;break;
	    case ';':a=CAN;break;
	    case ' ':a=SPA;break;
	    default:
		a=ERROR;
	}
	return a;
    }

    int formCheck(string form){
	int par=0;//かっこの数
	int ncnt=0;//数字が何文字目か(一文字目が0だと終了)
	int ecnt=0;//イコールの数
	int b=ERROR;//直前の語の種類(空白や異種の記号が来ると変わる)
	int bb=ERROR;
	for(int i=0; i<form.length(); i++){
	    char x = form[i];
	    switch(wILetter(x)){
		case NUM:
		    ncnt++;
		    if(ncnt == 1 && x == '0'){
//			return 0;
		    }
		    break;
		case ADD:
		    break;
		case OPP:
		    par++;
		    break;
		case CLP:
		    par--;
		    break;
		case SPA:
		    
		    break;
		case ERROR:
		    return 0;
		    break;
	    }
	    bb=b;
	    b=wILetter(x);
	}
	if (par!=0)return 0;//(と)の数が合わない
	return 1;
    }


//遂次処理。スタックを利用する。

    string execute(string input){
	string formula="";
	string output="";

	int t=wILetter(input[0]);
	if (t != NUM && t != CAN && t != OPP){
	    formula+=answer;
	}
	formula+=input;

	if (!formCheck(formula)){
	    answer="0";
	    return "ERROR;"+answer;
	}


	answer=formula;
	output=answer;


	return output;
    }
};




int main()
{

	string nformula;
	string answer;
	class Calculator dentaku;
	do{
	    nformula="";
	    answer="";
	    cout << ">>>" ;
	    cin >> nformula;
	    if (nformula=="end"){
		break;
	    }
	    answer = dentaku.execute(nformula);
	    cout << answer << endl;
	}while(1);
	
	return 0;

}

