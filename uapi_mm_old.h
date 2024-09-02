#ifndef __UAPI_MM__
#define __UAPI_MM__

#include <stdint.h>
typedef struct mm_instance_ mm_instance_t;

void *
xcalloc(mm_instance_t *mm_inst, char *struct_name, int units);
void *
xcalloc_buff(mm_instance_t *mm_inst, uint32_t bytes) ;
void
xfree(void *app_ptr);

/*Printing Functions*/
void mm_print_memory_usage(mm_instance_t *mm_inst,  char *struct_name);
void mm_print_block_usage(mm_instance_t *mm_inst);
void mm_print_registered_page_families(mm_instance_t *mm_inst);
void mm_print_variable_buffers(mm_instance_t *mm_inst);

/*Initialization Functions*/
void
mm_init();

mm_instance_t *
mm_init_new_instance();

/*Registration function*/
void
mm_instantiate_new_page_family(
        mm_instance_t *mm_inst,
        char *struct_name,
        uint32_t struct_size);

#define XCALLOC(mm_inst, units, struct_name) \
    (calloc(units, sizeof(struct_name)))

#define XCALLOC_BUFF(mm_inst, size_in_bytes) \
    (calloc(1, size_in_bytes))

#define MM_REG_STRUCT(mm_inst, struct_name)  \
    (mm_instantiate_new_page_family(mm_inst, #struct_name, sizeof(struct_name)))

#define XFREE(ptr)  \
   free(ptr)

#endif /* __UAPI_MM__ */
