// Mauricio Calderón Barazorda
// ED-A08


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

const int MAX_HORAS = 23;
const int MAX_MINUTOS = 59;
const int MAX_SEGUNDOS = 59;

class Horas {
    int hora;
    int minutos;
    int segundos;

public:
    Horas() : hora(0), minutos(0), segundos(0) {}
    Horas(int hora, int minutos, int segundos) {
        if (hora < 0 || hora > MAX_HORAS || minutos < 0 || minutos > MAX_MINUTOS || segundos < 0 || segundos > MAX_SEGUNDOS) {
            throw std::invalid_argument("Hora inválida");
        }

        this->hora = hora;
        this->minutos = minutos;
        this->segundos = segundos;
    }

    int getHora() const { return hora; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }

    bool operator< (Horas const& hs) const {
        if (this->getHora() < hs.getHora()) return true;
        else if (this->getHora() > hs.getHora()) return false;
        else if (this->getMinutos() < hs.getMinutos()) return true;
        else if (this->getMinutos() > hs.getMinutos()) return false;
        else if (this->getSegundos() < hs.getSegundos()) return true;
        else return false;
    }

    bool operator== (Horas const& hs) const {
        return this->getHora() == hs.getHora() && this->getMinutos() == hs.getMinutos()
            && this->getSegundos() == hs.getSegundos();
    }
};

inline std::istream& operator>> (std::istream& in, Horas& hs) {
    int hora, minutos, segundos;
    char c;

    in >> hora >> c >> minutos >> c >> segundos;

    if (hora < 0 || hora > MAX_HORAS || minutos < 0 || minutos > MAX_MINUTOS || segundos < 0 || segundos > MAX_SEGUNDOS) {
        throw std::invalid_argument("Hora inválida");
    }

    hs = Horas(hora, minutos, segundos);

    return in;

}

inline std::ostream& operator << (std::ostream& out, Horas const& hs) {
    out << std::setfill('0') << std::setw(2) << hs.getHora() << ':'
        << std::setfill('0') << std::setw(2) << hs.getMinutos() << ':'
        << std::setfill('0') << std::setw(2) << hs.getSegundos();
    return out;
}


// función que resuelve el problema
std::string resolver(Horas const& h1, Horas const& h2) {

    std::ostringstream resultado;

    if (h1 == h2) {
        resultado << "IGUALES";
    }
    else if (h1 < h2) {
        resultado << h1 << " " << h2;
    }
    else {
        resultado << h2 << " " << h1;
    }

    return resultado.str();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Horas hora1 = Horas(), hora2 = Horas();

    std::cin >> hora1 >> hora2;

    std::string sol = resolver(hora1, hora2);
    // escribir sol
    std::cout << sol << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
