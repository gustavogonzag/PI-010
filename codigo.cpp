#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;
    unsigned int N;
    string nome;
    float n1, n2;
    cout << "Digite o limite de alunos (N): ";
    cin >> N;

    while (nomes.size() < N) {
        cout << "Digite o nome do aluno: ";
        cin >> nome;
        cout << "Digite a primeira nota do aluno: ";
        cin >> n1;
        cout << "Digite a segunda nota do aluno: ";
        cin >> n2;
        nomes.push_back(nome);
        notas1.push_back(n1);
        notas2.push_back(n2);
    }

    cout << "====================" << endl;

    vector<string>::iterator it_nomes;
    vector<float>::iterator it_notas1;
    vector<float>::iterator it_notas2;
    bool trocou;

    do {
        trocou = false;
        for (size_t i = 0; i < nomes.size() - 1; i++) {
            if (nomes[i] > nomes[i + 1]) {
                swap(nomes[i], nomes[i + 1]);
                swap(notas1[i], notas1[i + 1]);
                swap(notas2[i], notas2[i + 1]);
                trocou = true;
            }
        }
    } while (trocou);

    for (size_t i = 0; i < nomes.size(); i++) {
        cout << "[" << i << "]    " << nomes[i] << "   " << notas1[i] << "   " << notas2[i] << endl;
    }

    char resposta;
    int indice;

    while (1) {
        cout << "Deseja excluir alunos? (s/n) ";
        cin >> resposta;
        if (resposta != 's')
            break;
        cout << "Digite qual o indice do aluno que voce deseja excluir: ";
        cin >> indice;
        if (indice >= 0 && indice < nomes.size()) {
            nomes.erase(nomes.begin() + indice);
            notas1.erase(notas1.begin() + indice);
            notas2.erase(notas2.begin() + indice);
        }
        for (size_t i = 0; i < nomes.size(); i++) {
            cout << "[" << i << "]    " << nomes[i] << "   " << notas1[i] << "   " << notas2[i] << endl;
        }
    }

    while (1) {
        cout << "Deseja incluir alunos (s/n) ";
        cin >> resposta;
        if (resposta != 's')
            break;

        cout << "Digite o nome do aluno: ";
        cin >> nome;
        cout << "Digite a primeira nota do aluno: ";
        cin >> n1;
        cout << "Digite a segunda nota do aluno: ";
        cin >> n2;

        size_t pos = 0;
        while (pos < nomes.size() && nome > nomes[pos]) {
            pos++;
        }

        nomes.insert(nomes.begin() + pos, nome);
        notas1.insert(notas1.begin() + pos, n1);
        notas2.insert(notas2.begin() + pos, n2);

        for (size_t i = 0; i < nomes.size(); i++) {
            cout << "[" << i << "]    " << nomes[i] << "   " << notas1[i] << "   " << notas2[i] << endl;
        }
    }
    return 0;
}
