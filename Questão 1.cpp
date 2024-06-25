#include <iostream>
#include <string>
#include <vector>
#include <cctype> // para std::isdigit

using namespace std;

struct Ramal {
    int numero;
    int categoria;
    string setor;
    int edificio;
    string sala;
    string responsavelRamal;
    string responsavelAteste;
};

bool validarNumero(int numero) {
    return numero >= 1000 && numero <= 2999;
}

bool validarCategoria(int categoria) {
    return categoria >= 0 && categoria <= 6;
}

bool validarEdificio(int edificio) {
    return edificio == 500 || edificio == 505;
}

bool validarSala(const string& sala) {
    if (sala.length() != 3) return false;
    if (!isdigit(sala[0]) || !isdigit(sala[1]) || !isdigit(sala[2])) return false;
    return true;
}

void cadastrarRamal(vector<Ramal>& ramais) {
    Ramal novoRamal;

    cout << "Numero do ramal: ";
    cin >> novoRamal.numero;
    if (!validarNumero(novoRamal.numero)) {
        cerr << "Numero do ramal invalido!\n";
        return;
    }

    cout << "Categoria: ";
    cin >> novoRamal.categoria;
    if (!validarCategoria(novoRamal.categoria)) {
        cerr << "Categoria invalida!\n";
        return;
    }

    cout << "Setor: ";
    cin.ignore();
    getline(cin, novoRamal.setor);

    cout << "Edificio de localizacao (500 ou 505): ";
    cin >> novoRamal.edificio;
    if (!validarEdificio(novoRamal.edificio)) {
        cerr << "Edificio invalido!\n";
        return;
    }

    cout << "Sala (formato 3 digitos, ex: 101): ";
    cin >> novoRamal.sala;
    if (!validarSala(novoRamal.sala)) {
        cerr << "Sala invalida!\n";
        return;
    }

    cout << "Responsavel pelo ramal: ";
    cin.ignore();
    getline(cin, novoRamal.responsavelRamal);

    cout << "Responsavel pelo ateste da conta telefonica: ";
    getline(cin, novoRamal.responsavelAteste);

    ramais.push_back(novoRamal);
    cout << "Ramal cadastrado com sucesso!\n";
}

void exibirRamais(const vector<Ramal>& ramais) {
    for (size_t i = 0; i < ramais.size(); ++i) {
        const Ramal& ramal = ramais[i];
        cout << "Numero: " << ramal.numero << "\n"
             << "Categoria: " << ramal.categoria << "\n"
             << "Setor: " << ramal.setor << "\n"
             << "Edificio: " << ramal.edificio << "\n"
             << "Sala: " << ramal.sala << "\n"
             << "Responsavel pelo ramal: " << ramal.responsavelRamal << "\n"
             << "Responsavel pelo ateste: " << ramal.responsavelAteste << "\n\n";
    }
}

int main() {
    vector<Ramal> ramais;
    int opcao;

    do {
        cout << "1. Cadastrar ramal\n2. Exibir ramais\n0. Sair\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarRamal(ramais);
                break;
            case 2:
                exibirRamais(ramais);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cerr << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
