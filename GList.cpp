typedef struct GNode* GList;
typedef int ElementType;

struct GNode {
	int Tag;
	union {
		ElementType Data;
		GList SubList;
	} URegion;
	GList Next;
};