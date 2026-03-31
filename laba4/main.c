#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Структура вершины дерева
typedef struct TreeNode {
    char* data;                  //указатель на строку 
    struct TreeNode** children;  //массив указателей на потомков
    size_t maxChildren;         //максимальная размерность списка потомков
} TreeNode;

//Создание новой вершины
TreeNode* createNode(size_t capacity) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed for node\n");
        exit(EXIT_FAILURE);
    }

    node->data = NULL;
    node->maxChildren = capacity;

    //Выделяем память для массива указателей на потомков
    node->children = (TreeNode**)calloc(capacity, sizeof(TreeNode*));
    if (!node->children) {
        fprintf(stderr, "Memory allocation failed for children array\n");
        free(node);
        exit(EXIT_FAILURE);
    }

    return node;
}

//Вставка строки
int insertString(TreeNode* root, const char* str) {
    if (!root) return 0;

    //Ищем свободный слот в текущей вершине
    for (size_t i = 0; i < root->maxChildren; ++i) {
        if (!root->children[i]) {
            //Создаём новую вершину с удвоенной размерностью
            root->children[i] = createNode(root->maxChildren * 2);

            //Копируем строку
            size_t strLen = strlen(str) + 1;
            root->children[i]->data = (char*)malloc(strLen * sizeof(char));
            if (!root->children[i]->data) {
                fprintf(stderr, "Memory allocation failed for string\n");
                free(root->children[i]);
                root->children[i] = NULL;
                return 0;
            }
            strcpy(root->children[i]->data, str);
            return 1; //Успешно вставлено
        }
    }

    //Если все слоты заняты, рекурсивно проверяем потомков
    for (size_t i = 0; i < root->maxChildren; ++i) {
        if (insertString(root->children[i], str)) {
            return 1;
        }
    }

    return 0; 
}

//Освобождение памяти
void freeTree(TreeNode* node) {
    if (!node) return;
    if (node->data) {
        free(node->data);
    }
    for (size_t i = 0; i < node->maxChildren; ++i) {
        freeTree(node->children[i]);
    }

    free(node->children);
    free(node);
}

//функция для печати дерева
void printTree(TreeNode* node, int level) {
    if (!node) return;
    for (int i = 0; i < level; ++i) {
        printf("  ");
    }

    if (node->data) {
        printf("Node: %s (children capacity: %zu)\n", node->data, node->maxChildren);
    } else {
        printf("Root (children capacity: %zu)\n", node->maxChildren);
    }

    //Рекурсивно печатаем потомков
    for (size_t i = 0; i < node->maxChildren; ++i) {
        printTree(node->children[i], level + 1);
    }
}

//Основная функция
int main() {
    const size_t N = 3; //начальная размерность корня

    //Создаём корень дерева
    TreeNode* root = createNode(N);

    //Добавляем строки
    insertString(root, "Первая строка");
    insertString(root, "Вторая строка");
    insertString(root, "Третья строка");

    //Четвёртая строка попадёт в потомка первой вершины (уровень 1)
    insertString(root, "Четвёртая строка");
    insertString(root, "Пятая строка");
    insertString(root, "Шестая строка");

    //Седьмая строка — в потомка на уровне 2
    insertString(root, "Седьмая строка");

    //Печатаем дерево для отладки
    printf("Структура дерева:\n");
    printTree(root, 0);

    //Освобождаем память
    freeTree(root);

    return 0;
}
