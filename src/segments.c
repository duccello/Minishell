#include "segments.h"
#include <stdbool.h>
#include <stdlib.h>
#include "data.h"
#include "token.h"

int		count_segments(char *s);

bool	split_segments(t_data *data, char *s)
{
	int		segments;
	int		i;

	segments = count_segments(s);
	return (true);
}

int		count_segments(char *s)
{
	int	i;
	bool quote;
	bool dquote;
	int	counter;

	quote = false;
	dquote = false;
	counter = 0;
	i = 0;
	while (s[i] != NULL)
	{
		toggle_quotes(s[i], &quote, &dquote);
		if (s[i] == '|' && quote == false && dquote == false)
			counter++;
	}
	return (counter);
}
