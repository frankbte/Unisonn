#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

//para ver si es mayuscula si es mayuscula es terminal
bool EsMayuscula(const string& str) {
    for (char c : str) {
        if (!isupper(c)) {
            return false;
        }
    }
    return true;
}


int colIndex(const string& t) {
    if (t == "+") return 0;
    if (t == "int") return 1;
    if (t == "(") return 2;
    if (t == ")") return 3;
    if (t == "$") return 4;
    return -1;
}


int renIndex(const string& noTer) {
    if (noTer == "E") return 0;
    if (noTer == "X") return 1;
    if (noTer == "T") return 2;
    return -1; //si no se conoce el  no terminal
}

int main() {
    string top, coltop;
    std::stack<string> s;
    std::queue<string> q;

    // pila der
    s.push("$");
    s.push("E");

   /* // cola tokens
    q.push("int"); //si acepta
    q.push("+");
    q.push("int");
    q.push("$");*/


    q.push("(");
    q.push("int");
    q.push(")");
    q.push("$");
    string TablaPar[3][5] = {
        //
        {"", "T X", "T X", "", ""},
        {"+ E", "", "", "EPSILON", "EPSILON"},
        {"", "int", "( E )", "", ""}
    };

    string regla;
    int ren, col;
    while (!s.empty()) {
        top = s.top();
        if (EsMayuscula(top)) {
            s.pop();
            if(!q.empty()){
            coltop = q.front();
            }
            ren = renIndex(top);
            col = colIndex(coltop);
            //cout<<"  PASO   ";
            if (ren != -1 && col != -1) {
                 regla = TablaPar[ren][col];
                cout<<"AQUI ESTA LA REGLA "<<regla;
                if (regla=="EPSILON"){
                    cout<<"ENTRO";
                    cout<<s.top();
                    continue;
                }

                if (!regla.empty()) {
                    std::stack<string> tempPila;
                    string token;
                    for (char c : regla) {
                        if (c != ' ') {
                            token += c;
                        } else if (!token.empty()) {
                            tempPila.push(token);       //agrega la regla basandose en el espacio
                            token.clear();
                        }
                    }
                    if (!token.empty()) {
                        tempPila.push(token);
                    }

                    while (!tempPila.empty()) {
                        s.push(tempPila.top());
                        tempPila.pop();
                    }
                    //string aux;
                    //aux=s.top();
                    //cout<<aux;
                                        // Mostrar el estado de la pila después de la inserción


                } else {
                    cout << "Error"<<endl;
                    break;
                }
            } else {
                cout << "Error"<<endl;
                break;
            }
        } else {
            if (top == coltop) {
                s.pop();
                q.pop();
                cout<<"\n ENTRO A POP CUANDO SON IGUALES \n";
            } else {
                cout << "Error" << endl;
                break;
            }
        }
        //si el top del stack es EPSILON
        //=s.top();

    }



    if (s.empty() && q.empty()) {
        cout << "Cadena aceptada." << endl;
    } else {
        cout << "Cadena no aceptada." << endl;
    }

    return 0;
}
