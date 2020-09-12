package bloom

import (
	"encoding/binary"
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
	data []uint64
}

func NewTrivialBloomFilter() *trivialBloomFilter {
	return &trivialBloomFilter{
		data: make([]uint64, 1000),
	}
}

func (b *trivialBloomFilter) Add(item string) {
	// Do nothing
}

func (b *trivialBloomFilter) MaybeContains(item string) bool {
	// Technically, any item "might" be in the set
	return true
}

func (b *trivialBloomFilter) MemoryUsage() int {
	return binary.Size(b.data)
}
