/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:41:59 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/02/29 20:03:03 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	rotate(float output[4][4], t_trigo_table *table)
{
	int	x = (int)table->x;
	int	y = (int)table->y;
	int	z = (int)table->z;
	output[0][0] = table->trigo[y].cos * table->trigo[z].cos;
	output[0][1] = table->trigo[x].sin * table->trigo[y].sin
		* table->trigo[z].cos - table->trigo[x].cos * table->trigo[z].sin;
	output[0][2] = table->trigo[x].cos * table->trigo[y].sin
		* table->trigo[z].cos + table->trigo[x].sin * table->trigo[z].sin;
	output[0][3] = 0.f;
	output[1][0] = table->trigo[y].cos * table->trigo[z].sin;
	output[1][1] = table->trigo[x].sin * table->trigo[y].sin
		* table->trigo[z].sin + table->trigo[x].cos * table->trigo[z].cos;
	output[1][2] = table->trigo[x].cos * table->trigo[y].sin
		* table->trigo[z].sin - table->trigo[x].sin * table->trigo[z].cos;
	output[1][3] = 0.f;
	output[2][0] = -table->trigo[y].sin;
	output[2][1] = table->trigo[x].sin * table->trigo[y].cos;
	output[2][2] = table->trigo[x].cos * table->trigo[y].cos;
	output[2][3] = 0.f;
	output[3][0] = 0.f;
	output[3][1] = 0.f;
	output[3][2] = 0.f;
	output[3][3] = 1.f;
}

void	translate(float output[4][4], t_vec3 *translate)
{
	output[0][0] = 1.f;
	output[0][1] = 0.f;
	output[0][2] = 0.f;
	output[0][3] = translate->x;
	output[1][0] = 0.f;
	output[1][1] = 1.f;
	output[1][2] = 0.f;
	output[1][3] = translate->y;
	output[2][0] = 0.f;
	output[2][1] = 0.f;
	output[2][2] = 1.f;
	output[2][3] = translate->z;
	output[3][0] = 0.f;
	output[3][1] = 0.f;
	output[3][2] = 0.f;
	output[3][3] = 1.f;
}

void	scale(float output[4][4], t_vec3 *scale)
{
	output[0][0] = scale->x;
	output[0][1] = 0.f;
	output[0][2] = 0.f;
	output[0][3] = 0.f;
	output[1][0] = 0.f;
	output[1][1] = scale->y;
	output[1][2] = 0.f;
	output[1][3] = 0.f;
	output[2][0] = 0.f;
	output[2][1] = 0.f;
	output[2][2] = scale->z;
	output[2][3] = 0.f;
	output[3][0] = 0.f;
	output[3][1] = 0.f;
	output[3][2] = 0.f;
	output[3][3] = 1.f;
}

void	isometric_transform(float output[4][4])
{
	float const	invsqrt_6 = 0.40825f;
	float const	sqrt_3 = 1.73205f;
	float const	sqrt_2 = 1.41421f;

	output[0][0] = invsqrt_6 * sqrt_3;
	output[0][1] = -invsqrt_6 * sqrt_3;
	output[0][2] = 0.f;
	output[0][3] = 0.f;
	output[1][0] = invsqrt_6;
	output[1][1] = invsqrt_6;
	output[1][2] = -2.f * invsqrt_6;
	output[1][3] = 0.f;
	output[2][0] = invsqrt_6 * sqrt_2;
	output[2][1] = invsqrt_6 * sqrt_2;
	output[2][2] = invsqrt_6 * sqrt_2;
	output[2][3] = 0.f;
	output[3][0] = 0.f;
	output[3][1] = 0.f;
	output[3][2] = 0.f;
	output[3][3] = 1.f;
}

//
// angle is atan(2)
//
void	cabinet_transform(float output[4][4])
{
	float const	half_cos_angle = 0.22360f;
	float const	half_sin_angle = 0.44721f;

	output[0][0] = 1.f;
	output[0][1] = 0.f;
	output[0][2] = half_cos_angle;
	output[0][3] = 0.f;
	output[1][0] = 0.f;
	output[1][1] = 1.f;
	output[1][2] = half_sin_angle;
	output[1][3] = 0.f;
	output[2][0] = 0.f;
	output[2][1] = 0.f;
	output[2][2] = 1.f;
	output[2][3] = 0.f;
	output[3][0] = 0.f;
	output[3][1] = 0.f;
	output[3][2] = 0.f;
	output[3][3] = 1.f;
}
