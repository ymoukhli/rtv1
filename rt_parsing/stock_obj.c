#include "rtparse.h"

void	ft_freeobj(t_obj **obj)
{
	while (*obj != NULL)
	{
		free(*obj);
		*obj = (*obj)->next;
	}
}

t_obj	*ft_new_obj(t_obj *obj,char *str_file)
{
	t_obj *new_obj;

	if (!(new_obj = (t_obj *)malloc(sizeof(t_obj))))
	{
		ft_strdel(&str_file);
		ft_freeobj(&obj);
		exit(0);
	}
	new_obj->next = NULL;
	return (new_obj);
}

char	*ft_nextnum(char *p)
{
	int i;

	i = 0;
	while (p[i] != 0 && ft_iswhit(p[i]) == 1)
		i++;
	while (ft_isdigit(p[i]) == 1)
		i++;
	while (ft_isdigit(p[i]) == 0 && p[i] != 0)
		i++;
	if (p[i] == 0)
		return (NULL);
	return (p + i);
}

t_vect	ft_stock_vec(char *p_obj, char *to_pick, int num)
{
	t_vect	vec;

	vec = (t_vect){0,0,0};
	p_obj = ft_strstr(p_obj, to_pick) + ft_strlen(to_pick);
	vec.x = ft_atoi(p_obj);
	p_obj = ft_nextnum(p_obj);
	if (num == 1)
		return (vec);
	vec.y = ft_atoi(p_obj);
	p_obj = ft_nextnum(p_obj);
	if (num == 2)
		return (vec);
	vec.z = ft_atoi(p_obj);
	return (vec);
}

void	ft_putobj(t_obj **obj, t_obj *n_obj)
{
	t_obj *p;

	p = *obj;
	if (*obj == NULL)
		*obj = n_obj;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = n_obj;
	}
}
void	ft_stock_plane(t_obj **obj, char *str_file, char *p_obj,int *a)
{
	t_obj *n_obj;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = plane;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->rot = ft_stock_vec(p_obj, "rot:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	n_obj->nor = ft_stock_vec(p_obj, "nor:", 3);
	ft_putobj(obj, n_obj);
}

void	ft_stock_sphere(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj	*n_obj;
	t_vect	v;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = sphere;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	v = ft_stock_vec(p_obj, "rad:", 1);
	n_obj->rad = v.x;
	ft_putobj(obj, n_obj);
}

void	ft_stock_cylinder(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj	*n_obj;
	t_vect	v;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = cylinder;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	n_obj->dir = ft_stock_vec(p_obj, "dir:", 3);
	n_obj->rot = ft_stock_vec(p_obj, "rot:", 3);
	v = ft_stock_vec(p_obj, "rad:", 1);
	n_obj->rad = v.x;
	ft_putobj(obj, n_obj);
}
void	ft_stock_cone(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj	*n_obj;
	t_vect	v;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = cone;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	n_obj->dir = ft_stock_vec(p_obj, "dir:", 3);
	n_obj->rot = ft_stock_vec(p_obj, "rot:", 3);
	v = ft_stock_vec(p_obj, "ang:", 1);
	n_obj->dif = v.x;
	ft_putobj(obj, n_obj);
}

void	ft_strlower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
}
t_obj	*ft_stock_obj(char *str_file)
{
	char *str_obj;
	char *p_obj;
	t_obj	*obj;
	int a = 0;

	obj = NULL;
	str_obj = ft_strstr(str_file, "obj {");
	ft_strlower(str_obj);
	if ((p_obj = ft_strstr(str_obj, "plane {")) != NULL)
		ft_stock_plane(&obj, str_file,p_obj,&a);
	if ((p_obj = ft_strstr(str_obj, "cone {")) != NULL)
		ft_stock_cone(&obj, str_file, p_obj,&a);
	if ((p_obj = ft_strstr(str_obj, "cylinder {")) != NULL)
		ft_stock_cylinder(&obj, str_file, p_obj,&a);
	if ((p_obj = ft_strstr(str_obj, "sphere {")) != NULL)
		ft_stock_sphere(&obj, str_file, p_obj,&a);
	return obj;
	//printf("pos: %f %f %f** trs: %f %f %f** col: %f %f %f** rad: %f** nor: %f %f %f\n", ob->pos.x, ob->pos.y, ob->pos.z, ob->trs.x, ob->trs.y, ob->trs.z ,ob->col.x ,ob->col.y, ob->col.z, ob->rad, ob->nor.x, ob->nor.y,ob->nor.z);
}
