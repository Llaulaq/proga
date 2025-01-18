#include <iostream>

/*
Var 1
Ввести последовательность натуральных чисел. 
Если последовательность упорядочена по неубыванию или по 
невозрастанию, удалить из последовательности числа, кратные 15, и 
продублировать простые числа. В противном случае упорядочить последовательность по 
невозрастанию первой цифры. Последовательность хранить в двусвязном циклическом списке 
с фиктивным элементом.
*/


struct Node {
    int data;
    Node* left;
    Node* right;
};


void addBack(Node* sent, int data) {
    Node* p = new Node;
    p->data = data;
    p->left = sent->left;
    p->right = sent;
    sent->left->right = p;
    sent->left = p;
}


bool read(int& cnt, Node* sent) {
    std::cout << "Enter the number of sequence elements: " << '\n';
    std::cin >> cnt;
    std::cout << "Enter the sequence elements: " << '\n';

    int num{};
    for (int i = 0; i < cnt; ++i) {
        std::cin >> num;
        if (num > 1) {
            addBack(sent, num);
        }
        else {
            std::cerr << "An unnatural number." << '\n';
            return false;
        }
    }
    return true;
}


void write(Node* sent) {
    Node* p = sent->right;
    while(p != sent) {
        std::cout << p->data << " ";
        p = p->right;
    }
}


void clear(Node* sent) {
    Node* p = sent->right;
    while(p != sent) {
        Node* tmp = p;
        p = p->right;
        delete tmp;
    }
    sent->left = sent;
    sent->right = sent;
}

int num15Dl(Node* sent) {
    int dl{ 0 };

    Node* p = sent->right;
    while(p != sent) {
        if(p->data % 15 == 0) {
            p->right->left = p->left;
            p->left->right = p->right;
            Node* tmp = p;
            p = p->right;
            delete tmp;
            dl++;
        }
        else {
            p = p->right;
        }  
    }
    return dl;
}

bool isPrime(int n) {
    for (int d = 2; d <= sqrt(n); ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

int primeDb(Node* sent) {
    int db{ 0 };

    Node* p = sent->right;
    while (p != sent) {
        if (isPrime(p->data)) {
            Node* q = new Node;
            q->data = p->data;
            q->right = p->right;
            q->left = p;
            p->right = q;
            q->right->left = q;
            p = q->right;
            db++;
        }
        else {
            p = p->right;
        }
    }
    return db;
}


void sortList(Node* sent) {
     for (Node* a = sent->right; a->right != sent; a = a->right)
        for (Node* b = a->right; b != sent; b = b->right)
            if (a->data < b->data) {
                std::swap(a->data, b->data);
            }
}


int main() {
    Node* sent = new Node;
    sent->left = sent;
    sent->right = sent;

    int cnt{};
    if (!read(cnt, sent)){
        return -1;
    }

    int dl = num15Dl(sent);
    int db = primeDb(sent);

    if (dl || db) {
        write(sent);
    } 
    else {
        sortList(sent);
        write(sent);
    }

    clear(sent);
    delete sent;
    return 0;
}