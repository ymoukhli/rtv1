#include "rtparse.h"

char	*ft_pick_str(char *str, char *start, char *end)
{
	int i;
	char *p_s;
	char *p_e;
	char *stri;

	i = 0;
	p_s = ft_strstr(str, start);
	if (p_s == NULL)
		return NULL;
	if (p_s[1] != '\0')
		p_e = ft_strstr(p_s + 1, end);
	else
		return NULL;
	if (p_s == NULL || p_e == NULL)
		return NULL;
	i = p_e - p_s;
	stri = ft_strsub(p_s, 0, i + 1);
	return stri;
}

char	*ft_obj_pick_str(char *str, char *start, char end, char skip_end)
{
	char *p_s;
	int i;
	int count;
	int j;

	if (!(p_s = ft_strstr(str, start)))
		return NULL;
	i = ft_strlen(start);
	count = 0;
	j = 0;
	while (p_s[i] != 0)
	{
		if (p_s[i] == end)
		{
			if (count == 0)
			{
				j = i;
				break ;
			}
			else
				count--;
		}
		if (p_s[i] == skip_end)
			count++;
		i++;
	}
	if (j == 0)
		return 0;
	return ft_strsub(p_s, 0, j + 1);
}

int		ft_check(char *str, char *pick, int nnum)
{
	char *str_pick;
	int i;
	int k;

	if (!(str_pick = ft_strstr(str,pick)))
		return -1;
	i = ft_strlen(pick);
	k = 0;
	while (str_pick[i] != '\0')
	{
		if (ft_isdigit(str_pick[i]))
		{
			k++;
			while (ft_isdigit(str_pick[i]))
				i++;
		}
		if (str_pick[i] == ';')
			break ;
		else if (str_pick[i] != ',' && str_pick[i] != ' ' &&
				str_pick[i] != '\t' && str_pick[i] != '\n')
			return -1;
		if (str_pick[i] != '\0')
			i++;
	}
	if (k == nnum)
		return (0);
	return (-1);
}
