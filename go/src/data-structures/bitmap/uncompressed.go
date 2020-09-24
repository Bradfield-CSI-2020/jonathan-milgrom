package bitmap

const wordSize = 64

type BitMapBlock = []uint64

type uncompressedBitmap struct {
	data []uint64
}

func newUncompressedBitmap() *uncompressedBitmap {
	return &uncompressedBitmap{}
}

func Make(size uint32) uncompressedBitmap {
	data := make(BitMapBlock, size+2)
	return uncompressedBitmap{data: data}
}

func (b *uncompressedBitmap) Get(x uint32) bool {
	block, bit := locate(x)
	num := b.data[block]
	return (num | bit) == num
}

func (b *uncompressedBitmap) Set(x uint32) {
	block, bit := locate(x)
	b.data[block] = b.data[block] | bit
}

func (b *uncompressedBitmap) Union(other *uncompressedBitmap) *uncompressedBitmap {
	data := make(BitMapBlock, cap(b.data))
	for i, word := range b.data {
		otherWord := other.data[i]
		data[i] = word | otherWord
	}
	return &uncompressedBitmap{
		data: data,
	}
}

func (b *uncompressedBitmap) Intersect(other *uncompressedBitmap) *uncompressedBitmap {
	data := make(BitMapBlock, cap(b.data))
	for i, word := range b.data {
		otherWord := other.data[i]
		data[i] = word & otherWord
	}
	return &uncompressedBitmap{
		data: data,
	}
}

func locate(decimal uint32) (uint64, uint64) {
	/*
		Identify the block of memory in the []uint64 array.
		e.g
			13 / 64 => 0th block
			78 / 64 => 1st block
	*/
	block := indexFromNumber(decimal)

	/*
		Identify which bit in the block to target, and represent as a binary integer
		e.g.
			4: 1 << (4 % 64) => 1 << 4 => 0b10000 (i.e the 4th index)
	*/
	bit := 1 << (decimal % wordSize)

	return uint64(block), uint64(bit)
}

func indexFromNumber(x uint32) uint32 {
	return x / wordSize
}
