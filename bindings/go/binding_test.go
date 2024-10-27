package tree_sitter_mustache_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_mustache "github.com/tree-sitter/tree-sitter-mustache/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_mustache.Language())
	if language == nil {
		t.Errorf("Error loading Mustache grammar")
	}
}
