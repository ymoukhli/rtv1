#include "rtparse.h"

int		ft_light_check(char *str_file)
{
	char *light_str;
	// take from 'light {' to '}'
	if (!(light_str = ft_pick_str(str_file, "light {", "}")))
		return ft_error(NULL, 11);
	if (ft_strstr(light_str, "cam {") != NULL || ft_strstr(light_str, "obj {"))
		return ft_error(&light_str, 9);
	if (ft_check(light_str,"pos:", 3) || ft_check(light_str, "int:", 1))
		return ft_error(&light_str, 0);
	printf("%s\n", light_str);
	ft_strdel(&light_str);
	return 1;	
}
