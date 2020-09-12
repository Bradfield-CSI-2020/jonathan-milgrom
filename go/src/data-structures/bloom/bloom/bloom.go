package bloom

import (
	"encoding/binary"
	"hash/fnv"
)

const (
	size = 10000000
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
	index := hash(item)
	b.data[index] = 1
}

func (b *trivialBloomFilter) MaybeContains(item string) bool {
	// Technically, any item "might" be in the set
	index := hash(item)
	return b.data[index] == 1
}

func (b *trivialBloomFilter) MemoryUsage() int {
	return binary.Size(b.data)
}

func hash(item string) uint32 {
	hash := fnv.New32()
	hash.Write([]byte(item))
	number := hash.Sum32()
	return number % size
}
