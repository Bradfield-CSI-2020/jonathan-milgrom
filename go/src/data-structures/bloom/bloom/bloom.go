package bloom

import (
	"data-structures/bloom/bitVector"
	"encoding/binary"
	"hash"
	"hash/adler32"
	"hash/fnv"
)

const (
	size = 800000
)

type BloomFilter interface {
	Add(item string)

	// `false` means the item is definitely not in the set
	// `true` means the item might be in the set
	MaybeContains(item string) bool

	// Number of bytes used in any underlying storage
	MemoryUsage() int

	String() string
}

type bloomFilter struct {
	data bitVector.BitVector
}

func NewBloomFilter() *bloomFilter {
	return &bloomFilter{
		data: bitVector.Make(size),
	}
}

func (b *bloomFilter) Add(item string) {
	index1, index2 := doublehash(item)
	b.data.Set(int(index1))
	b.data.Set(int(index2))
}

func (b *bloomFilter) MaybeContains(item string) bool {
	index1, index2 := doublehash(item)
	return b.data.Has(int(index1)) && b.data.Has(int(index2))
}

func (b *bloomFilter) MemoryUsage() int {
	return binary.Size(b.data)
}

func (b *bloomFilter) String() string {
	return b.data.String()
}

func doublehash(item string) (uint32, uint32) {
	return stringToInt(fnv.New32(), item) % size, stringToInt(adler32.New(), item) % size
}

func stringToInt(h hash.Hash32, item string) uint32 {
	h.Write([]byte(item))
	return h.Sum32()
}
