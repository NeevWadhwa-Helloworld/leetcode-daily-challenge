/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 5003

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

unsigned int hash(const char* str) {
    unsigned int h = 0;
    while (*str) {
        h = h * 31 + *str++;
    }
    return h % HASH_SIZE;
}

void insert(Node** table, const char* word) {
    unsigned int h = hash(word);
    Node* curr = table[h];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = table[h];
    table[h] = new_node;
}

int get_count(Node** table, const char* word) {
    unsigned int h = hash(word);
    Node* curr = table[h];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0;
}

void free_table(Node** table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp->word);
            free(temp);
        }
        table[i] = NULL;
    }
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || wordsSize == 0) return NULL;

    int s_len = strlen(s);
    int word_len = strlen(words[0]);
    int total_words_len = wordsSize * word_len;

    if (s_len < total_words_len) return NULL;

    Node* word_counts[HASH_SIZE] = {NULL};
    for (int i = 0; i < wordsSize; i++) {
        insert(word_counts, words[i]);
    }

    int* result = (int*)malloc(sizeof(int) * (s_len - total_words_len + 1));
    char* temp_word = (char*)malloc(sizeof(char) * (word_len + 1));

    for (int i = 0; i < word_len; i++) {
        int left = i;
        int right = i;
        int count = 0;
        Node* curr_counts[HASH_SIZE] = {NULL};

        while (right + word_len <= s_len) {
            strncpy(temp_word, s + right, word_len);
            temp_word[word_len] = '\0';
            right += word_len;

            int target_count = get_count(word_counts, temp_word);
            if (target_count > 0) {
                insert(curr_counts, temp_word);
                count++;

                while (get_count(curr_counts, temp_word) > target_count) {
                    char* left_word = (char*)malloc(sizeof(char) * (word_len + 1));
                    strncpy(left_word, s + left, word_len);
                    left_word[word_len] = '\0';
                    
                    unsigned int h = hash(left_word);
                    Node* curr = curr_counts[h];
                    while (curr) {
                        if (strcmp(curr->word, left_word) == 0) {
                            curr->count--;
                            break;
                        }
                        curr = curr->next;
                    }
                    
                    count--;
                    left += word_len;
                    free(left_word);
                }

                if (count == wordsSize) {
                    result[(*returnSize)++] = left;
                }
            } else {
                free_table(curr_counts);
                count = 0;
                left = right;
            }
        }
        free_table(curr_counts);
    }

    free(temp_word);
    free_table(word_counts);

    return result;
}
