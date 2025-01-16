#include <iostream>

using namespace std;


//Var 1
/* Ввести последовательность натуральных чисел.
Если последовательность упорядочена по невозрастанию первой или последней цифры,
удалить из последовательности составные числа и продублировать простые числа,
содержащие цифры 1, 5 или 7. В противном случае упорядочить последовательность по неубыванию.
Последовательность хранить в односвязном списке.
*/


struct Node {
    int data;     // полезная информация, хранящаяся в этом узле
    Node* next;  
};

// Распечатать список
void print(Node* top) {
    Node* p = top;  // Адрес текущего элемента списка
    while (p != nullptr) {
        cout << p->data << " ";  // Печатаем полезную информацию текущего узла
        p = p->next;  // Адрес следующего узла становится текущим
    }
}

// Функция, проверяющая на невозрастание первой цифры
bool non_growthFirstdigit(Node* top) {
    Node* p = top; // Адрес текущего узла списка
    while (p->next != nullptr) {
        if (p->data <= p->next->data) {
            return false;

        } else {
            p = p->next;
        }
    }
    return true;
}

bool non_growthLastdigit(Node* top) {
    Node* p = top; // Адрес текущего узла списка
    while (p->next != nullptr) {
        if ((p->data % 10) <= (p->next->data % 10)) {
            return false;

        }
        else {
            p = p->next;
        }
    }
    return true;
}


// Отсортировать список по неубыванию (алгоритм сортировки обменами)
void sort_list(Node* top) {
    for (Node* a = top; a->next != nullptr; a = a->next)
        for (Node* b = a->next; b->next != nullptr; b = b->next)
            if (a->data > b->data) swap(a->data, b->data);
}

bool prostDel(int n) {
    while (n != 0) {
        int x = n % 10;
        if (x == 1 || x == 5 || x == 7) {
            return true;
        }
        n /= 10;
    }
    return false;
}



// Продублировать в списке все продублировать простые числа, содержащие цифры 1, 5 или 7
void duplicate_numbers(Node* top) {
    Node* p = top;
    while (p != nullptr) {
        if (prostDel(p->data)) {
            Node* q = new Node;  // Создаём новый узел
            q->data = p->data;    // и заполняем содержимое,
            q->next = p->next;    // а также прописываем адреса.
            p->next = q;
            p = q->next;
        }
        else {
            p = p->next;  // Иначе адрес следующего узла становится текущим.
        }
    }
}

bool isPrime(int n) {
    for (int d = 2; d <= sqrt(n); ++d) {
        if (n % d == 0) {
            return false;
        }
        return true;
    }
}


// Удалить из списка все составные числа
void remove_numbers(Node*& top) {
    // Если удаляемое число расположено на вершине
    while (top != nullptr && !isPrime(top->data)) {
        Node* temp = top->next;
        delete top;
        top = temp;
    }

    Node* p = top;
    while (p != nullptr && p->next != nullptr) {
        Node* temp = p->next;
        if (!isPrime(temp->data)) {
            p->next = temp->next;
            delete temp;
        }
        else {
            p = temp;
        }
    }
}

// Удаление списка
void delete_list(Node* top) {
    Node* p = top;
    while (p != nullptr) {
        Node* temp = p->next;
        delete p;
        p = temp;
    }
}


int main() {

    Node* top = nullptr;

    int n;    // Количество элементов последовательности,
    cin >> n; 

    // Первый элемент последовательности читаем отдельно
    int x;
    cin >> x;

    top = new Node;
    top->data = x;
    top->next = nullptr;

    Node* pp = top;

    // Все остальные элементы последовательности читаем в цикле.
    for (int i = 1; i < n; i++) {
        cin >> x;
        Node* p = new Node;  
        pp->next = p;  
        p->data = x;  
        p->next = nullptr;  
        pp = p;  
    }

    if (non_growthFirstdigit(top) || non_growthLastdigit(top)) {
        remove_numbers(top);
        duplicate_numbers(top);
    } 
    else {
        sort_list(top);
    }

    print(top);


    delete_list(top);

    return 0;
}