package bloom

import (
	"encoding/binary"
	"hash"
	"hash/adler32"
	"hash/fnv"
)

const (
	size = 1000000
)

type BloomFilter interface {
	Add(item string)

	// `false` means the item is definitely not in the set
	// `true` means the item might be in the set
	MaybeContains(item string) bool

	// Number of bytes used in any underlying storage
	MemoryUsage() int
}

type trivialBloomFilter struct {
	data []byte
}

func NewTrivialBloomFilter() *trivialBloomFilter {
	return &trivialBloomFilter{
		data: make([]byte, size),
	}
}

func (b *trivialBloomFilter) Add(item string) {
	i1, i2 := doublehash(item)
	b.data[i1] = 1
	b.data[i2] = 1
}

func (b *trivialBloomFilter) MaybeContains(item string) bool {
	i1, i2 := doublehash(item)
	return b.data[i1] == 1 && b.data[i2] == 1
}

func (b *trivialBloomFilter) MemoryUsage() int {
	return binary.Size(b.data)
}

func doublehash(item string) (uint32, uint32) {
	return stringToIntModulo(fnv.New32(), item), stringToIntModulo(adler32.New(), item)
}

func stringToIntModulo(h hash.Hash32, item string) uint32 {
	h.Write([]byte(item))
	number := h.Sum32()
	return number % size
}
