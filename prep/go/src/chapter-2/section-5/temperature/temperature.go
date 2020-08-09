package temperature

import "fmt"

const format = "%.2f\u00B0%c"

// Celcius expresses float64 number in celcius units
type Celcius float64

// Fahrenheit expresses float64 number in fahrenheit units
type Fahrenheit float64

// ToF converts type Celcius to a number in fahrenheit units
func (c Celcius) ToF() Fahrenheit {
	return Fahrenheit(c*9/5 + 32)
}

func (c Celcius) String() string {
	return fmt.Sprintf(format, c, 'C')
}

// ToC converts type Fahrenheit to a number in celcius units
func (f Fahrenheit) ToC() Celcius {
	return Celcius((f - 32) * 5 / 9)
}

func (f Fahrenheit) String() string {
	return fmt.Sprintf(format, f, 'F')
}
