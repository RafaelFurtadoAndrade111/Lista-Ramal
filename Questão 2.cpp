#include <iostream>
#include <string>
#include <vector>
#include <cctype> // para std::isdigit
#include <set> // para std::set

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

vector<Ramal> ramais; // Vetor global para armazenar os ramais

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

bool ramalExiste(int numero) {
    for (size_t i = 0; i < ramais.size(); ++i) {
        if (ramais[i].numero == numero) {
            return true;
        }
    }
    return false;
}

void cadastrarRamal() {
    Ramal novoRamal;

    cout << "Numero do ramal: ";
    cin >> novoRamal.numero;
    if (!validarNumero(novoRamal.numero)) {
        cerr << "Numero do ramal invalido!\n";
        return;
    }
    if (ramalExiste(novoRamal.numero)) {
        cerr << "Numero de ramal ja existe!\n";
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

void exibirRamais() {
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

void listarOpcoesPesquisa() {
    cout << "Metodos de pesquisa:\n";
    cout << "1. Pesquisar por setor\n";
    cout << "2. Pesquisar por responsavel pelo ramal\n";
    cout << "3. Pesquisar por responsavel pelo ateste\n";
    cout << "Escolha uma opcao: ";
}

void removerDuplicatas(vector<string>& lista) {
    set<string> s(lista.begin(), lista.end());
    lista.assign(s.begin(), s.end());
}

void pesquisarPorSetor() {
    vector<string> setores;
    for (size_t i = 0; i < ramais.size(); ++i) {
        setores.push_back(ramais[i].setor);
    }
    removerDuplicatas(setores);

    cout << "Setores disponiveis:\n";
    for (size_t i = 0; i < setores.size(); ++i) {
        cout << i + 1 << ". " << setores[i] << "\n";
    }

    int escolha;
    cout << "Escolha um setor: ";
    cin >> escolha;

    if (escolha < 1 || escolha > setores.size()) {
        cerr << "Escolha invalida!\n";
        return;
    }

    string setorEscolhido = setores[escolha - 1];
    cout << "Ramais no setor " << setorEscolhido << ":\n";
    for (size_t i = 0; i < ramais.size(); ++i) {
        if (ramais[i].setor == setorEscolhido) {
            cout << "Numero: " << ramais[i].numero << "\n"
                 << "Categoria: " << ramais[i].categoria << "\n"
                 << "Edificio: " << ramais[i].edificio << "\n"
                 << "Sala: " << ramais[i].sala << "\n"
                 << "Responsavel pelo ramal: " << ramais[i].responsavelRamal << "\n"
                 << "Responsavel pelo ateste: " << ramais[i].responsavelAteste << "\n\n";
        }
    }
}

void pesquisarPorResponsavelRamal() {
    vector<string> responsaveis;
    for (size_t i = 0; i < ramais.size(); ++i) {
        responsaveis.push_back(ramais[i].responsavelRamal);
    }
    removerDuplicatas(responsaveis);

    cout << "Responsaveis disponiveis:\n";
    for (size_t i = 0; i < responsaveis.size(); ++i) {
        cout << i + 1 << ". " << responsaveis[i] << "\n";
    }

    int escolha;
    cout << "Escolha um responsavel: ";
    cin >> escolha;

    if (escolha < 1 || escolha > responsaveis.size()) {
        cerr << "Escolha invalida!\n";
        return;
    }

    string responsavelEscolhido = responsaveis[escolha - 1];
    cout << "Ramais do responsavel " << responsavelEscolhido << ":\n";
    for (size_t i = 0; i < ramais.size(); ++i) {
        if (ramais[i].responsavelRamal == responsavelEscolhido) {
            cout << "Numero: " << ramais[i].numero << "\n"
                 << "Categoria: " << ramais[i].categoria << "\n"
                 << "Setor: " << ramais[i].setor << "\n"
                 << "Edificio: " << ramais[i].edificio << "\n"
                 << "Sala: " << ramais[i].sala << "\n"
                 << "Responsavel pelo ateste: " << ramais[i].responsavelAteste << "\n\n";
        }
    }
}

void pesquisarPorResponsavelAteste() {
    vector<string> responsaveis;
    for (size_t i = 0; i < ramais.size(); ++i) {
        responsaveis.push_back(ramais[i].responsavelAteste);
    }
    removerDuplicatas(responsaveis);

    cout << "Responsaveis disponiveis:\n";
    for (size_t i = 0; i < responsaveis.size(); ++i) {
        cout << i + 1 << ". " << responsaveis[i] << "\n";
    }

    int escolha;
    cout << "Escolha um responsavel: ";
    cin >> escolha;

    if (escolha < 1 || escolha > responsaveis.size()) {
        cerr << "Escolha invalida!\n";
        return;
    }

    string responsavelEscolhido = responsaveis[escolha - 1];
    cout << "Ramais do responsavel " << responsavelEscolhido << ":\n";
    for (size_t i = 0; i < ramais.size(); ++i) {
        if (ramais[i].responsavelAteste == responsavelEscolhido) {
            cout << "Numero: " << ramais[i].numero << "\n"
                 << "Categoria: " << ramais[i].categoria << "\n"
                 << "Setor: " << ramais[i].setor << "\n"
                 << "Edificio: " << ramais[i].edificio << "\n"
                 << "Sala: " << ramais[i].sala << "\n"
                 << "Responsavel pelo ramal: " << ramais[i].responsavelRamal << "\n\n";
        }
    }
}

void pesquisarRamais() {
    listarOpcoesPesquisa();

    int metodo;
    cin >> metodo;

    switch (metodo) {
        case 1:
            pesquisarPorSetor();
            break;
        case 2:
            pesquisarPorResponsavelRamal();
            break;
        case 3:
            pesquisarPorResponsavelAteste();
            break;
        default:
            cerr << "Metodo de pesquisa invalido!\n";
    }
}

int main() {
    int opcao;

    do {
        cout << "1. Cadastrar ramal\n2. Exibir ramais\n3. Pesquisar ramais\n0. Sair\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarRamal();
                break;
            case 2:
                exibirRamais();
                break;
            case 3:
                pesquisarRamais();
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
