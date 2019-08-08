#include "rtparse.h"

int		ft_cam_check(char *str_file)
{
	char *cam_str;
	if (!(cam_str = ft_pick_str(str_file, "cam {", "}")))
		return ft_error(NULL, 10);
	if (ft_strstr(cam_str, "light {") != NULL || ft_strstr(cam_str, "obj {"))
		return ft_error(&cam_str, 8);
	if (ft_check(cam_str,"pos:", 3) || ft_check(cam_str,"trs:", 3)
	|| ft_check(cam_str, "rot:", 3))
		return ft_error(&cam_str, 1);
	printf("%s\n", cam_str);
	ft_strdel(&cam_str);
	return 1;	
}
