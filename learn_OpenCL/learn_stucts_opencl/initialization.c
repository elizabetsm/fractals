/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 22:06:08 by sbecker           #+#    #+#             */
/*   Updated: 2019/04/15 11:02:00 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_program.h"
#define PROGRAM_FILE "check_struct.cl"

cl_device_id    get_device_id(void)
{
	cl_platform_id      platform; //Платформа дающая доступ к устройтсву
	cl_device_id        device; //устройство
	int err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err != 0)
		printf ("Get platform - error\n");
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (err != 0)
		printf ("Get device id - error\n");
	return (device);
}

cl_kernel   get_kernel(cl_device_id *device, cl_context context)
{
	cl_program          program;
	FILE    *fd;
	char    *program_buf;
	size_t  program_size;
	int     err;
	cl_kernel kernel;

	fd = fopen(PROGRAM_FILE, "r");
	if (!fd)
		printf ("Open kernel file - bad\n");
	printf ("%ud", (unsigned int)fd);
	fseek(fd, 0, SEEK_END); //сместить указатель в файле на конец файла
	program_size = ftell(fd); //кол-во байт в файле
	rewind(fd); //вернуть указатель на начало фалйа
	program_buf = (char*)malloc(program_size + 1);
	fread(program_buf, sizeof(char), program_size, fd);
	program_buf[program_size] = '\0';
	fclose(fd);
	program = clCreateProgramWithSource(context, 1, (const char**)&program_buf,
			(const size_t*)&program_size, &err);
	err = clBuildProgram(program, 1, device, NULL, NULL, NULL);
	if (err != 0)
		printf ("build program - error\n");
	kernel = clCreateKernel(program, "check_struct", &err);
	if (err != 0)
		printf ("create kernel - error\n");
	return (kernel);
}

void    initialization_CL(t_cl *cl)
{
	cl_device_id        device;
	int err;

	device = get_device_id();
	cl->context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
	if (err != 0)
		printf ("create context - bad\n");
	cl->queue = clCreateCommandQueue(cl->context, device, 0, &err);
	if (err != 0)
		printf ("create command queue - bad\n");
	cl->kernel = get_kernel(&device, cl->context);
}

void	initialization_conf(t_conf *conf)
{
	conf->x_len = 800;
	conf->y_len = 800;
	conf->z_len = 800;
}
