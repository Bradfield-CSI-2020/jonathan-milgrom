package bitVector

import "fmt"

const (
	blockSize = 64
)

type BitVector []uint64

func Make(size int) BitVector {
	return make(BitVector, size)
}

func (b BitVector) Set(decimal int) {
	block, bit := locate(decimal)
	b[block] = b[block] | uint64(bit)
}

func (b BitVector) Has(decimal int) bool {
	block, bit := locate(decimal)
	num := b[block]
	return (num | uint64(bit)) == num
}

func (b BitVector) String() string {
	var s string
	for _, num := range b {
		s = fmt.Sprintf("%b", num) + s
	}
	return s
}

func locate(decimal int) (int, int) {
	/*
		Identify the block of memory in the []uint64 array.
		e.g
			13 / 64 => 0th block
			78 / 64 => 1st block
	*/
	block := decimal / blockSize

	/*
		Identify which bit in the block to target, and represent as a binary integer
		e.g.
			4: 1 << (4 % 64) => 1 << 4 => 0b10000 (i.e the 4th index)
	*/
	bit := 1 << (decimal % blockSize)

	return block, bit
}
