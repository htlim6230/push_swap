void	rotate_a(t_data *s)
{
	int	temp;
	int	i;

	if (s-> size_a < 2)
		return ;
	temp = s->a[0];
	i = 0;
	while (i < (s->size_a - 1))
	{
		s->a[i] = s->a[i+1];
		i++;
	}
	s->a[size_a - 1] = temp;
	wrote(1, "ra\n", 3);
	//ft_putstr_fd("ra", 1);
}

void	rotate_b(t_data *s)
{
	int	temp;
	int	i;

	if (s-> size_b < 2)
		return ;
	temp = s->b[0];
	i = 0;
	while (i < (s->size_b - 1))
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[size_b - 1] = temp;
	wrote(1, "rb\n", 3);
	//ft_putstr_fd("rb", 1);
}

void	rotate_ab(t_data *s)
{
	rotate_a(s);
	rotate_b(s);
	wrote(1, "rr\n", 3);
	//ft_putstr_fd("rr", 1);
}

void	reverse_rotate_a(t_data *s)
{
	int	temp;
	int	i;

	if (s-> size_a < 2)
		return ;
	temp = s->a[s->size_a - 1];
	i = s->size_a - 1;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = temp;
	wrote(1, "rra\n", 4);
	//ft_putstr_fd("rra", 1);
}

void	reverse_rotate_b(t_data *s)
{
	int	temp;
	int	i;

	if (s-> size_b < 2)
		return ;
	temp = s->b[s->size_b - 1];
	i = s->size_b - 1;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = temp;
	write(1, "rrb\n", 4);
	//ft_putstr_fd("rrb", 1);
}

void	reverse_rotate_ab(t_data *s)
{
	revere_rotate_a(s);
	reverse_rotate_b(s);
	write(1, "rrr\n", 5);
	//ft_putstr_fd("rrr", 1);
}