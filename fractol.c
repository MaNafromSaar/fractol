int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "Usage: ./fractol mandelbrot/julia param1 param2\n", 43);
        return (0);
    }
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        mandelbrot();
    else if (ft_strcmp(argv[1], "julia") == 0)
        julia();
    else
    {
        write(1, "Usage: ./fractol mandelbrot/julia param1 param2\n", 49);
        return (0);
    }
}