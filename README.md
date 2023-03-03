
# BSQ

You must find the largest possible square on a board while avoiding obstacles.
The board can be generated two ways. The first one is by reading a file passed as the program’s argument.

The file is valid if it is respecting those constraints:

    • its first line contains the number of lines on the board (and only that),
    • “.” (representing an empty place) and “o” (representing an obstacle) are the only two characters for the other lines,
    • all of the lines are of the same length (except the first one),
    • it contains at least one line,
    • each line is terminated by ‘\n’.
You program must print the board, with some “.” replaced by “x” to represent the largest square you found.


## Run

Clone the project

```bash
  git clone https://github.com/SkyfightTV/BSQ.git
```

Go to the project directory

```bash
  cd BSQ
```

Create binary file

```bash
  make 
```

### To solve a map

```bash
  ./bsq [map_path]
```

### To generate a map

```bash
  ./bsq [map_size] [map_pattern]
```


## Demo

### Solve map

![Solve image](https://cdn.discordapp.com/attachments/820068689264246814/1081326877756625058/image.png)

### Generate map

![Generate image](https://cdn.discordapp.com/attachments/820068689264246814/1081327112549585007/image.png)

## Running Tests

To run tests, run the following command

```bash
  make tests_run
```

To create coverage folder, run the following command

```bash
  make coverage
```
## Authors

- [@SkyfightTV](https://github.com/SkyfightTV)
