#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include <limits>

class Organism {
public:
    virtual void eat() = 0;
    virtual std::string getType() = 0;
};

class Predator : public Organism {
public:
    Predator(std::string type) : type(type) {}
    void eat() {
        std::cout << type << " съел " << target->getType() << std::endl;
    }
    std::string getType() {
        return type;
    }
    void setTarget(Organism* t) {
        target = t;
    }
private:
    std::string type;
    Organism* target;
};

class Herbivore : public Organism {
public:
    Herbivore(std::string type) : type(type) {}
    void eat() {
        std::cout << type << " съело " << target->getType() << std::endl;
    }
    std::string getType() {
        return type;
    }
    void setTarget(Organism* t) {
        target = t;
    }
private:
    std::string type;
    Organism* target;
};

class Plant : public Organism {
public:
    Plant(std::string type) : type(type) {}
    void eat() {
        std::cout << type << " было съедено" << std::endl;
    }
    std::string getType() {
        return type;
    }
private:
    std::string type;
};

std::vector<Organism*> organisms;
std::vector<std::string> events; // Вектор для хранения истории событий

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void feed() {
    clearScreen();
    if (organisms.empty()) {
        std::cout << "Все померли" << std::endl;
        return;
    }
    int predatorIndex = rand() % organisms.size();
    Predator* predator = dynamic_cast<Predator*>(organisms[predatorIndex]);
    if (predator) {
        int targetIndex;
        do {
            targetIndex = rand() % organisms.size();
        } while (targetIndex == predatorIndex || dynamic_cast<Plant*>(organisms[targetIndex]) != nullptr || dynamic_cast<Predator*>(organisms[targetIndex]) != nullptr); // Проверка, что цель - не растение и не хищник
        Organism* target = organisms[targetIndex];
        predator->setTarget(target);
        predator->eat();
        organisms.erase(organisms.begin() + targetIndex);
        events.push_back(predator->getType() + " съел " + target->getType());
    }
    else {
        int herbivoreIndex = rand() % organisms.size();
        Herbivore* herbivore = dynamic_cast<Herbivore*>(organisms[herbivoreIndex]);
        if (herbivore) {
            int targetIndex = rand() % organisms.size();
            Plant* plant = dynamic_cast<Plant*>(organisms[targetIndex]);
            if (plant) {
                herbivore->setTarget(plant);
                herbivore->eat();
                organisms.erase(organisms.begin() + targetIndex);
                events.push_back(herbivore->getType() + " съело " + plant->getType());
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int numPredators;
    std::cout << "Введите количество хищников: ";
    std::cin >> numPredators;
    for (int i = 0; i < numPredators; ++i) {
        std::string type;
        std::cout << "Введите тип растения " << i + 1 << ": ";
        std::cin >> type;
        organisms.push_back(new Plant(type));
    }

    while (!organisms.empty()) {
        std::cout << "Нажмите 1 для продолжения или 2 для кормления: ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "1") {
            continue;
        }
        else if (input == "2") {
            feed();
        }
        else {
            std::cout << "Неверный выбор!" << std::endl;
        }
    }

    std::cout << "Описание процесса:" << std::endl;
    for (const std::string& event : events) {
        std::cout << event << std::endl;
    }

    // Очистка памяти
    for (Organism* organism : organisms) {
        delete organism;
    }

    return 0;
}

