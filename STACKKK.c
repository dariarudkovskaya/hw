#define STACK_EMPTY_ERROR -100

#include <stdio.h>
#include <stdlib.h>

// Если мы создаём новый тип-структуру, полем которого является указатель на этот же тип,
//то его необходимо объявлять явно с использованием служебного слова struct


// (отдельно выделили структуру *StackStruct*)

typedef struct StackStruct
{
	int value;
	struct StackStruct *nextNode;
} StackStruct;

StackStruct* stackCreate(const int);

// добавление элемента в начало списка
// указатель на указатель - то на что указывает , лежит в структуре
void stackPush(StackStruct**, const int);
int stackPop(StackStruct**);


void stackPrint(const StackStruct*);

int main()
{
// Создание списка c первым элементом 10
    
    StackStruct* newStack = stackCreate(10);
    
    // добавление элемента в начало списка
    // создание какого-то элемента (значения , закидываемые в стек)
    
	stackPush(&newStack, 20);
	stackPush(&newStack, 30);
    
    // выводим элементы из стека newStack
	stackPrint(newStack);

    //удалить эл-т из стека newstack
	//stackPop(&newStack);
	//stackPop(&newStack);
    
	stackPrint(newStack);
	// poppy - эл-т, который вынут из стека в функции stackPop
    // в poppy кладется значение, которое снимает функция stackPop ( result )
    for (int i = 0; i < 4; i++) {
        int poppy = stackPop(&newStack);
        printf("\npoppied value = %d\n\n", poppy);
    }
	stackPrint(newStack);
	
	stackPush(&newStack, -20);
	stackPush(&newStack, 70);
    
	stackPrint(newStack);
    
	//освобождает место в памяти , которое занимал стек
	free(newStack);
	
	return 0;
}

StackStruct* stackCreate(const int newValue)
{
    // выделить память под элементы
    //  метод sizeof вычисляет размер элемента
    //  метод malloc выделяет требуемое количество памяти
    // установить указатели на выделенные фрагменты памяти
    // добавление элементов в начало списка ?

    
	StackStruct* newStack = (StackStruct*)malloc(sizeof(StackStruct));
        // формирование информативной части
	newStack->value = newValue;
    // формирование адресной части
	newStack->nextNode = NULL;
	return newStack;
}

// \* Функция Pop удаляет из списка головной узел */
// указатель на указатель - то на что указывает , лежит в структуре
int stackPop(StackStruct** stack)
{
	StackStruct* poppedNode = *stack;
    
    // если это не poppedNode , то пиши *Ошибка, стек пустой

	if(!poppedNode){
		exit(STACK_EMPTY_ERROR);
	}
	*stack = (*stack)->nextNode;
	int result = poppedNode->value;
	free(poppedNode);
	return result;
}
// добавление эл-в в начало списка *

void stackPush(StackStruct** stack, const int newValue)
{
	StackStruct* next = stackCreate(newValue);
	next->nextNode = *stack;
    //в next запис адрес stack
	*stack = next;
}
// вывод элементов
void stackPrint(const StackStruct* stack)
{
	if(!stack){
		return;
	}
	while(stack) {
		printf("%d ", stack->value);
          // указ на след узел
		stack = stack->nextNode;
	}
	printf("\n");
}
