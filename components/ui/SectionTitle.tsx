export function SectionTitle({ eyebrow, title, description }: { eyebrow: string; title: string; description?: string }) {
  return <div className="section-title"><p className="eyebrow">{eyebrow}</p><div><h2>{title}</h2>{description && <p>{description}</p>}</div></div>;
}
