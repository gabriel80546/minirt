
#include "minirt.h"

int	can_light_see_this_hit(t_hit temp_temp_hit, t_vars vars, t_list *result)
{
	t_list	*temp_result;

	while (result != NULL)
	{
		if (distance(vars.light.pos, *(t_vec *)result->data) + EPSILON <
			distance(vars.light.pos, temp_temp_hit.ponto))
			return (0);
		temp_result = result;
		result = result->next;
	}
	result = temp_result;
	// if (result != NULL)
	// 	clear_list_all(result);
	return (1);
}
