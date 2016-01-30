#include "singleendreader.h"

namespace prefixMatching {
SingleEndReader::SingleEndReader(const string &seq_file,file_format format)
    :seqfile_(seq_file),format_(format),total_reads_(0)
{
    this->init();
}
void SingleEndReader::init() {
    if (format_ == FASTA) {
        this->file_reader_.reset(new fastaPattern(seqfile_));

    } else if (format_ == FASTQ) {
        this->file_reader_.reset(new fastqPattern(seqfile_));

    } else {
        throw invalid_argument("Does not support given sequence file format!\n"
                               "ONLY supports fastq or fasta format.");
    }
}
} // namespace prefixMatching
