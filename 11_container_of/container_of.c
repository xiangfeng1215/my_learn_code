#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/* include/linux/kernel.h:
 * container_of - cast a member of a structure out to the containing structure
 * @ptr: the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:    the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({	    \
		const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
		(type *)( (char *)__mptr - offsetof(type,member) );})

struct student {
	char name[32];
	int age;
	double score;
};

int main(void)
{
	struct student *stu;
	struct student stu1 = {"zxf", 18, 89.4};
	double *page = &(stu1.score); 

	stu = container_of(page, struct student, score);

	printf("stu1's name is %s\n",stu->name);
	printf("stu1's age is %d\n",stu->age);
	printf("stu1's score is %.2f\n",stu->score);

	return 0;
}

