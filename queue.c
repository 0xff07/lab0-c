#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q)
        goto oom_q;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;

oom_q:
    return NULL;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (!q)
        goto null_q;
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *ptr = q->head;
    while (ptr) {
        list_ele_t *tmp = ptr->next;
        free(ptr->value);
        free(ptr);
        ptr = tmp;
    }
    free(q);

null_q:
    return;
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)
        goto null_q;

    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        goto oom_node;

    int len = strlen(s);
    char *_s = malloc(sizeof(char) * (len + 1));
    if (!_s)
        goto oom_string;

    strncpy(_s, s, len + 1);
    newh->value = _s;
    newh->next = q->head;

    q->head = newh;
    if (!q->size) {
        q->tail = newh;
    }
    q->size++;
    return true;

oom_string:
    free(newh);
oom_node:
null_q:
    return false;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q)
        goto null_q;

    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        goto oom_node;

    int len = strlen(s);
    char *_s = malloc(sizeof(char) * (len + 1));
    if (!_s)
        goto oom_string;

    strncpy(_s, s, len + 1);
    newh->value = _s;
    newh->next = NULL;

    if (!q->tail) {
        q->tail = newh;
        q->head = newh;
    } else {
        q->tail->next = newh;
        q->tail = newh;
    }
    q->size++;
    return true;

oom_string:
    free(newh);
oom_node:
null_q:
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q)
        goto null_q;

    if (!q->head)
        goto empty_q;

    list_ele_t *tmp = q->head;
    q->head = q->head->next;

    if (sp) {
        strncpy(sp, tmp->value, bufsize);
        sp[bufsize - 1] = 0;
    }

    free(tmp->value);
    free(tmp);
    q->size--;
    return true;

empty_q:
null_q:
    return false;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q)
        goto null_q;

    return q->size;

null_q:
    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q)
        goto null_q;

    if (!q->size)
        goto empty_q;

    q->tail = q->head;

    list_ele_t *head_new = NULL, *head_old = NULL;
    head_new = q->head;
    head_old = q->head->next;
    head_new->next = NULL;
    while (head_old) {
        list_ele_t *tmp = head_old->next;
        head_old->next = head_new;
        head_new = head_old;
        head_old = tmp;
    }
    q->head = head_new;
    return;
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
empty_q:
null_q:
    return;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
