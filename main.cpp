#include <iostream>
#include "string"
#include <stdlib.h>

class steak {
public:
    explicit steak() {
        head = nullptr;
    }

    void add_f(int data) {
        if (head == nullptr) {
            head = new node(data);
        } else {
            node *current = new node(data);
            head->pre = current;
            current->next = head;
            head = current;
        }
    }

    void del() {
        node *temp = this->head;
        head = head->next;
        delete (temp);
    }

    int hd() {
        return head->data;
    }

private:
    class node {
    public:
        node *next, *pre;
        int data;

        explicit node(int data, node *next = nullptr, node *pre = nullptr) {
            this->data = data;
            this->next = next;
            this->pre = pre;
        }
    };

    node *head;
};

int main() {
    steak s;
    std::string str;
    std::getline(std::cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            if (isdigit(str[i])) {
                s.add_f(atoi(&(str[i])));
            } else if (str[i] == '+') {
                int a, b;
                a = s.hd();
                s.del();
                b = s.hd();
                s.del();
                s.add_f(b + a);
            } else if (str[i] == '-') {
                int a, b;
                a = s.hd();
                s.del();
                b = s.hd();
                s.del();
                s.add_f(a - b);
            } else if (str[i] == '*') {
                int a, b;
                a = s.hd();
                s.del();
                b = s.hd();
                s.del();
                s.add_f(b * a);
            }
        }
    }
    std::cout << s.hd();
}