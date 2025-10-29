pandoc README.md -o CSE241_Assignment.pdf \
  --pdf-engine=pdflatex \
  -V geometry:margin=0.5in \
  -V fontsize=10pt \
  -V linestretch=0.9
